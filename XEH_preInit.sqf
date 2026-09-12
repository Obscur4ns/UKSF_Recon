if (!hasInterface) exitWith {};

UKSF_Recon_fnc_adjustTripodSplay = {
    params ["_direction"];

    private _tripod = vehicle player;

    if (!(_tripod isKindOf "Leupold_ProGuide_Spotting")) exitWith {false};
    if ((gunner _tripod) != player) exitWith {false};

    private _phase = _tripod animationSourcePhase "tripod_splay";
    private _next = (((_phase + (_direction * 0.65 * diag_deltaTime)) max 0) min 1);

    if (abs (_next - _phase) < 0.0001) exitWith {true};

    _tripod animateSource ["tripod_splay", _next, true];

    true
};

[
    ["UKSF Recon", "Tripod"],
    "TripodSplayOut",
    ["Splay Legs", "Hold to splay the tripod legs wider"],
    { [1] call UKSF_Recon_fnc_adjustTripodSplay },
    {},
    [0, [false, false, false]],
    true,
    0
] call CBA_fnc_addKeybind;

[
    ["UKSF Recon", "Tripod"],
    "TripodSplayIn",
    ["Bring Legs In", "Hold to bring the tripod legs inward"],
    { [-1] call UKSF_Recon_fnc_adjustTripodSplay },
    {},
    [0, [false, false, false]],
    true,
    0
] call CBA_fnc_addKeybind;