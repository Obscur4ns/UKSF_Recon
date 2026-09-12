class CfgPatches
{
    class UKSF_Recon
    {
        author = "UKSF Surplus";
        requiredAddons[] =
        {
            "A3_Weapons_F",
            "A3_Anims_F",
            "cba_common",
            "cba_xeh",
            "cba_keybinding",
            "ace_main",
            "ace_common",
            "ace_apl",
            "ace_interaction"
        };
        requiredVersion = 0.1;
    };
};
class CfgWeapons
{
    class Binocular;
    class Rangefinder;
    class CBA_MiscItem;
    class CBA_MiscItem_ItemInfo;
    class Tripod_Item: CBA_MiscItem
    {
        scope = 2;
        displayName = "[ZXX] Vortex Summit Carbon II Tripod";
        author = "UKSF Surplus";
        model = "\UKSF_Recon\Tripod_Item.p3d";
        picture = "\UKSF_Recon\data\UI\tripod_arsenal_ca.paa";
        class ItemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 15;
        };
    };
    class Leupold_ProGuide_Tripod_Item: CBA_MiscItem
    {
        scope = 2;
        displayName = "[ZXX] Leupold Pro Guide CF-436 Tripod";
        author = "UKSF Surplus";
        model = "\UKSF_Recon\Tripod_Stowed.p3d";
        picture = "\UKSF_Recon\data\UI\proguide_arsenal_ca.paa";

        class ItemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 15;
        };
    };
    class Leupold_Spotting_Scope_Handheld: Binocular
    {
        author = "UKSF Surplus";
        scope = 2;
        displayName = "[ZXX] Leupold Mk4 Spotting Scope";
        model = "\UKSF_Recon\Mk4_Handheld.p3d";
        picture = "\UKSF_Recon\data\UI\spotting_scope_arsenal_ca.paa";
        weaponInfoType = "Mk4_Rangefinder";
        opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur2"};
        opticsZoomMax = "0.25/12";
        opticsZoomMin = "0.25/40";
        distanceZoomMin = 200;
        distanceZoomMax = 1800;
        opticsZoomInit = "0.25/12";
        visionMode[] = {};
        discretefov[] =
        {
            "0.25/12",
            "0.25/20",
            "0.25/32",
            "0.25/40"
        };
        modelOptics[] =
        {
            "\UKSF_Recon\1240_mildot12.p3d",
            "\UKSF_Recon\1240_mildot20.p3d",
            "\UKSF_Recon\1240_mildot32.p3d",
            "\UKSF_Recon\1240_mildot40.p3d"
        };
        discreteInitIndex = 0;
        discreteDistance[] =
        {
            100,200,300,400,500,600,700,800,900,
            1000,1100,1200,1300,1400,1500,1600,1700,1800
        };
        discreteDistanceInitIndex = 1;
        class WeaponSlotsInfo
        {
            mass = 15;
        };
    };
};
class CfgVehicles
{
    class Item_Base_F;
    class LandVehicle;
    class StaticWeapon: LandVehicle
    {
        class Turrets
        {
            class MainTurret;
        };
        class ACE_Actions
        {
            class ACE_MainActions;
        };
    };
    class Leupold_Spotting_Scope: StaticWeapon
    {
        displayName = "[ZXX] Leupold Mk4 Spotting Scope";
        scope = 2;
        radarType = 0;
        showAllTargets = 0;
        unitInfoType = "RscUnitInfoStaticNoWeapon";
        side = 1;
        faction = "BLU_F";
        model = "\UKSF_Recon\Mk4_Tripod.p3d";
        receiveRemoteTargets = false;
        reportRemoteTargets = false;
        reportOwnPosition = false;
        threat[] = {1,0.05,0.05};
        driverForceOptics = true;
        accuracy = 3.5;
        cost = 4;
        memoryPointDriverOptics = "gunnerview";
        driverOpticsModel = "\UKSF_Recon\1240_mildot12.p3d";
        driverIsCommander = true;
        ace_dragging_canDrag = 1;
        ace_dragging_canCarry = 1;
        ace_cookoff_probability = 0;
        destrType = "destructDefault";
        armor = 80;
        class DestructionEffects {};

        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                memoryPointsGetInGunner = "pos gunner";
                memoryPointsGetInGunnerDir = "pos gunner dir";
                gunnerName = "Spotter";
                gunnerCompartments = "Compartment1";
                proxyIndex = 1;
                forceHideGunner = true;
                gunnerAction = "Mortar_Gunner";
                maxElev = 45;
                minElev = -45;
                maxTurn = 70;
                minTurn = -70;
                stabilizedInAxes = 3;
                primaryGunner = 1;
                primaryCommander = 0;
                commanding = 1;
                dontCreateAI = true;
                weapons[] = {"Laserdesignator_mounted"};
                gunnerOpticsColor[] = {1,1,1,1};
                gunnerOpticsModel = "\UKSF_Recon\1240_mildot12.p3d";
                gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
                animationSourceBody = "MainTurret";
                animationSourceGun = "MainGun";
                animationSourceElevation = "ObsElevation";
                turretInfoType = "Mk4_Rangefinder";
                class Hitpoints {};
                class OpticsIn
                {
                    class Zoom12
                    {
                        opticsDisplayName = "12x Zoom";
                        initAngleX = 0;
                        minAngleX = -70;
                        maxAngleX = 70;
                        initAngleY = 0;
                        minAngleY = -100;
                        maxAngleY = 100;
                        visionMode[] = {};
                        minFov = "0.25/12";
                        maxFov = "0.25/12";
                        initFov = "0.25/12";
                        gunnerOpticsModel = "\UKSF_Recon\1240_mildot12.p3d";
                    };
                    class Zoom20: Zoom12
                    {
                        opticsDisplayName = "20x Zoom";
                        minFov = "0.25/20";
                        maxFov = "0.25/20";
                        initFov = "0.25/20";
                        gunnerOpticsModel = "\UKSF_Recon\1240_mildot20.p3d";
                    };
                    class Zoom32: Zoom12
                    {
                        opticsDisplayName = "32x Zoom";
                        minFov = "0.25/32";
                        maxFov = "0.25/32";
                        initFov = "0.25/32";
                        gunnerOpticsModel = "\UKSF_Recon\1240_mildot32.p3d";
                    };
                    class Zoom40: Zoom12
                    {
                        opticsDisplayName = "40x Zoom";
                        minFov = "0.25/40";
                        maxFov = "0.25/40";
                        initFov = "0.25/40";
                        gunnerOpticsModel = "\UKSF_Recon\1240_mildot40.p3d";
                    };
                };
            };
        };
        class ACE_Actions: ACE_Actions
        {
            class ACE_MainActions: ACE_MainActions
            {
                selection = "tripod_axis";
                class spotting_scope_pickup_inv
                {
                    displayName = "Pickup Spotting Scope";
                    icon = "\UKSF_Recon\data\UI\spotting_scope_ace.paa";
                    selection = "";
                    distance = 5;
                    condition = "(alive _target) && (isNull gunner _target) && (_player canAdd ['Tripod_Item',2]) && (binocular _player != '')";
                    statement = "_player addItem 'Tripod_Item'; _player addItem 'Leupold_Spotting_Scope_Handheld'; deleteVehicle _target;";
                    showDisabled = 0;
                };
                class spotting_scope_pickup_weap
                {
                    displayName = "Pickup Spotting Scope";
                    icon = "\UKSF_Recon\data\UI\spotting_scope_ace.paa";
                    selection = "";
                    distance = 5;
                    condition = "(alive _target) && (isNull gunner _target) && (_player canAdd ['Tripod_Item',2]) && (binocular _player == '')";
                    statement = "_player addItem 'Tripod_Item'; _player addItem 'Leupold_Spotting_Scope_Handheld'; deleteVehicle _target;";
                    showDisabled = 0;
                };
            };
        };
    };
    class Leupold_ProGuide_Spotting: StaticWeapon
    {
        displayName = "[ZXX] Leupold Pro Guide CF-436 Tripod w/ Leupold Mk4 Spotting Scope";
        author = "UKSF Surplus";
        scope = 2;
        side = 1;
        faction = "BLU_F";
        model = "\UKSF_Recon\Tripod_Full_Spotting.p3d";
        radarType = 0;
        showAllTargets = 0;
        receiveRemoteTargets = false;
        reportRemoteTargets = false;
        reportOwnPosition = false;
        unitInfoType = "RscUnitInfoStaticNoWeapon";
        accuracy = 3.5;
        cost = 4;
        threat[] = {0,0,0};
        ace_dragging_canDrag = 1;
        ace_dragging_canCarry = 1;
        ace_cookoff_probability = 0;
        destrType = "destructDefault";
        armor = 80;
        class DestructionEffects {};
        class AnimationSources
        {
            class tripod_retract
            {
                source = "user";
                animPeriod = 1;
                initPhase = 0;
            };
            class tripod_splay
            {
                source = "user";
                animPeriod = 1;
                initPhase = 0;
            };
            class tripod_height
            {
                source = "user";
                animPeriod = 1;
                initPhase = 0;
            };
            class gunner_proxy_x
            {
                source = "user";
                animPeriod = 0;
                initPhase = 0.5;
            };
            class gunner_proxy_y
            {
                source = "user";
                animPeriod = 0;
                initPhase = 0.5;
            };
            class gunner_proxy_z
            {
                source = "user";
                animPeriod = 0;
                initPhase = 0.5;
            };
        };
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                body = "mainTurret";
                gun = "mainGun";
                turretAxis = "osaveze";
                gunAxis = "osahlavne";
                gunBeg = "usti hlavne";
                gunEnd = "konec hlavne";
                animationSourceBody = "mainTurret";
                animationSourceGun = "mainGun";
                animationSourceElevation = "ObsElevation";
                memoryPointGunnerOptics = "gunnerview";
                memoryPointsGetInGunner = "pos gunner";
                memoryPointsGetInGunnerDir = "pos gunner dir";
                proxyIndex = 1;
                gunnerName = "Spotter";
                gunnerCompartments = "Compartment1";
                forceHideGunner = true;
                gunnerAction = "UKSF_Recon_Spotter_IK_Test";
                gunnerRightHandAnimName = "scope_hand_r";
                minTurn = -90;
                maxTurn = 90;
                initTurn = 0;
                minElev = -33.117;
                maxElev = 27.616;
                initElev = 0;
                stabilizedInAxes = 0;
                primaryGunner = 1;
                primaryCommander = 0;
                commanding = 1;
                dontCreateAI = true;
                weapons[] = {"Laserdesignator_mounted"};
                gunnerOpticsColor[] = {1,1,1,1};
                gunnerOpticsModel = "\UKSF_Recon\1240_mildot12.p3d";
                gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
                turretInfoType = "Mk4_Rangefinder";
                class Hitpoints {};
                class OpticsIn
                {
                    class Zoom12
                    {
                        opticsDisplayName = "12x Zoom";
                        initAngleX = 0;
                        minAngleX = -70;
                        maxAngleX = 70;
                        initAngleY = 0;
                        minAngleY = -100;
                        maxAngleY = 100;
                        visionMode[] = {};
                        minFov = "0.25/12";
                        maxFov = "0.25/12";
                        initFov = "0.25/12";
                        gunnerOpticsModel = "\UKSF_Recon\1240_mildot12.p3d";
                    };
                    class Zoom20: Zoom12
                    {
                        opticsDisplayName = "20x Zoom";
                        minFov = "0.25/20";
                        maxFov = "0.25/20";
                        initFov = "0.25/20";
                        gunnerOpticsModel = "\UKSF_Recon\1240_mildot20.p3d";
                    };
                    class Zoom32: Zoom12
                    {
                        opticsDisplayName = "32x Zoom";
                        minFov = "0.25/32";
                        maxFov = "0.25/32";
                        initFov = "0.25/32";
                        gunnerOpticsModel = "\UKSF_Recon\1240_mildot32.p3d";
                    };
                    class Zoom40: Zoom12
                    {
                        opticsDisplayName = "40x Zoom";
                        minFov = "0.25/40";
                        maxFov = "0.25/40";
                        initFov = "0.25/40";
                        gunnerOpticsModel = "\UKSF_Recon\1240_mildot40.p3d";
                    };
                };
            };
        };
    class ACE_Actions: ACE_Actions
    {
        class ACE_MainActions: ACE_MainActions
        {
            selection = "";
            class spotting_scope_pickup_inv
            {
                displayName = "Pickup Spotting Scope";
                icon = "\UKSF_Recon\data\UI\spotting_scope_ace.paa";
                selection = "";
                distance = 5;
                condition = "(alive _target) && " "(isNull gunner _target) && " "(_player canAdd ['Tripod_Item',2]) && " "(binocular _player != '')";
                statement = "_player addItem 'Tripod_Item'; " "_player addItem 'Leupold_Spotting_Scope_Handheld'; " "deleteVehicle _target;";
                showDisabled = 0;
            };
            class spotting_scope_pickup_weap
            {
                displayName = "Pickup Spotting Scope";
                icon = "\UKSF_Recon\data\UI\spotting_scope_ace.paa";
                selection = "";
                distance = 5;
                condition = "(alive _target) && " "(isNull gunner _target) && " "(_player canAdd ['Tripod_Item',2]) && " "(binocular _player == '')";
                statement = "_player addItem 'Tripod_Item'; " "_player addItem 'Leupold_Spotting_Scope_Handheld'; " "deleteVehicle _target;";
                showDisabled = 0;
            };
        };
    };
};
    class Man;
    class CAManBase: Man
    {
        class ACE_SelfActions
        {
            class ACE_Equipment
            {
                class spotting_scope_place_inv
                {
                    displayName = "Deploy Spotting Scope";
                    icon = "\UKSF_Recon\data\UI\spotting_scope_ace.paa";
                    condition = "('Tripod_Item' in (items _player)) && ('Leupold_Spotting_Scope_Handheld' in (items _player)) && (binocular _player != 'Leupold_Spotting_Scope_Handheld')";
                    statement = "_spottingScopeObj = 'Leupold_Spotting_Scope'; _spottingScope = _spottingScopeObj createVehicle (position _player); _spottingScope setposASL (_player modelToWorldWorld [0,1,0.5]); _spottingScope setDir getDir _player; createVehicleCrew (_spottingScope); _player removeItem 'Tripod_Item'; _player removeItem 'Leupold_Spotting_Scope_Handheld';";
                    showDisabled = 0;
                };
                class spotting_scope_place_weap
                {
                    displayName = "Deploy Spotting Scope";
                    icon = "\UKSF_Recon\data\UI\spotting_scope_ace.paa";
                    condition = "('Tripod_Item' in (items _player)) && ('Leupold_Spotting_Scope_Handheld' in (items _player)) && (binocular _player == 'Leupold_Spotting_Scope_Handheld')";
                    statement = "_spottingScopeObj = 'Leupold_Spotting_Scope'; _spottingScope = _spottingScopeObj createVehicle (position _player); _spottingScope setposASL (_player modelToWorldWorld [0,1,0.5]); _spottingScope setDir getDir _player; createVehicleCrew (_spottingScope); _player removeItem 'Tripod_Item'; _player removeItem 'Leupold_Spotting_Scope_Handheld';";
                    showDisabled = 0;
                };
            };
        };
    };
};
class RscControlsGroup
{
    class VScrollbar;
    class HScrollbar;
};
class RscText;
class RscInGameUI
{
    class RscUnitInfo;
    class Mk4_Rangefinder: RscUnitInfo
    {
        idd = -1;
        controls[] = {"CA_IGUI_elements_group"};
        class CA_IGUI_elements_group: RscControlsGroup
        {
            idc = -1;
            class VScrollbar: VScrollbar
            {
                width = 0;
            };
            class HScrollbar: HScrollbar
            {
                height = 0;
            };
            x = "0 * (0.01875 * SafezoneH) + (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
            y = "0 * (0.025 * SafezoneH) + (SafezoneY)";
            w = "50 * (0.01875 * SafezoneH)";
            h = "40 * (0.025 * SafezoneH)";
            class controls
            {
                class CA_Distance: RscText
                {
                    idc = 198;
                    style = 0;
                    sizeEx = "0.04 * SafezoneH";
                    colorText[] = {0.706,0.0745,0.0196,1};
                    shadow = 0;
                    font = "LCD14";
                    x = "40 * (0.01875 * SafezoneH)";
                    y = "16 * (0.025 * SafezoneH)";
                    w = "6 * (0.01875 * SafezoneH)";
                    h = "1.5 * (0.025 * SafezoneH)";
                };
                class CA_Heading: RscText
                {
                    idc = 156;
                    style = 0;
                    sizeEx = "0.04 * SafezoneH";
                    colorText[] = {0.706,0.0745,0.0196,1};
                    shadow = 0;
                    font = "LCD14";
                    x = "40 * (0.01875 * SafezoneH)";
                    y = "14 * (0.025 * SafezoneH)";
                    w = "6 * (0.01875 * SafezoneH)";
                    h = "1.5 * (0.025 * SafezoneH)";
                };
            };
        };
    };
};