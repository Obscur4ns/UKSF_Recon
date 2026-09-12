if (!hasInterface) exitWith {};
if (!isNil "UKSF_Recon_spotterControllerRunning") exitWith {};
UKSF_Recon_spotterControllerRunning = true;

[] spawn {
    private _endpoints = [
        "UKSF_Recon_Spotter_StandHigh",
        "UKSF_Recon_Spotter_Stand",
        "UKSF_Recon_Spotter_StandLow",
        "UKSF_Recon_Spotter_KneelHigh",
        "UKSF_Recon_Spotter_Kneel",
        "UKSF_Recon_Spotter_KneelLow",
        "UKSF_Recon_Spotter_ProneHigh",
        "UKSF_Recon_Spotter_Prone"
    ];

    private _gestures = [
        "UKSF_Recon_Spotter_StandHigh_Arms",
        "",
        "UKSF_Recon_Spotter_StandLow_Arms",
        "",
        "UKSF_Recon_Spotter_Kneel_Arms",
        "UKSF_Recon_Spotter_KneelLow_Arms",
        "UKSF_Recon_Spotter_ProneHigh_Arms",
        "UKSF_Recon_Spotter_Prone_Arms"
    ];

    private _downTransitions = [
        "UKSF_Recon_Spotter_Down_StandHigh_Stand",
        "UKSF_Recon_Spotter_Down_Stand_StandLow",
        "UKSF_Recon_Spotter_Down_StandLow_KneelHigh",
        "UKSF_Recon_Spotter_Down_KneelHigh_Kneel",
        "UKSF_Recon_Spotter_Down_Kneel_KneelLow",
        "UKSF_Recon_Spotter_Down_KneelLow_ProneHigh",
        "UKSF_Recon_Spotter_Down_ProneHigh_Prone"
    ];

    private _upTransitions = [
        "",
        "UKSF_Recon_Spotter_Up_Stand_StandHigh",
        "UKSF_Recon_Spotter_Up_StandLow_Stand",
        "UKSF_Recon_Spotter_Up_KneelHigh_StandLow",
        "UKSF_Recon_Spotter_Up_Kneel_KneelHigh",
        "UKSF_Recon_Spotter_Up_KneelLow_Kneel",
        "UKSF_Recon_Spotter_Up_ProneHigh_KneelLow",
        "UKSF_Recon_Spotter_Up_Prone_ProneHigh"
    ];

    private _getRawTarget = {
        params ["_height", "_splay"];

        if (_height < 0.14) exitWith {0};
        if (_height < 0.44) exitWith {2};
        if (_height < 0.73) exitWith {4};
        if (_height < 0.94) exitWith {5};
        if (_height >= 0.99 && {_splay >= 0.99}) exitWith {7};

        6
    };

    private _activeTripod = objNull;
    private _currentIndex = -1;
    private _wantedIndex = -1;
    private _activeGesture = "";

    private _transitionActive = false;
    private _transitionEnd = 0;
    private _transitionNextIndex = -1;

    while {true} do {
        private _unit = player;
        private _tripod = vehicle _unit;

        private _valid =
            alive _unit
            && {_tripod isKindOf "Leupold_ProGuide_Spotting"}
            && {gunner _tripod isEqualTo _unit};

        if (!_valid) then {
            if !(_activeGesture isEqualTo "") then {
                _unit switchGesture "";
            };

            _activeTripod = objNull;
            _currentIndex = -1;
            _wantedIndex = -1;
            _activeGesture = "";

            _transitionActive = false;
            _transitionEnd = 0;
            _transitionNextIndex = -1;

            missionNamespace setVariable ["UKSF_Recon_spotterCurrentIndex", -1];
            missionNamespace setVariable ["UKSF_Recon_spotterWantedIndex", -1];

            sleep 0.05;
        } else {
            if !(_activeGesture isEqualTo "") then {
                if ((toLowerANSI (gestureState _unit)) != (toLowerANSI _activeGesture)) then {
                    _unit switchGesture [_activeGesture,0,1,false];
                };
            };

            private _height = (_tripod animationSourcePhase "ObsElevation") max 0 min 1;
            private _splay = (_tripod animationSourcePhase "tripod_splay") max 0 min 1;

            if !(_tripod isEqualTo _activeTripod) then {
                _activeTripod = _tripod;

                _wantedIndex = [_height, _splay] call _getRawTarget;
                _currentIndex = _wantedIndex;

                _transitionActive = false;
                _transitionEnd = 0;
                _transitionNextIndex = -1;

                _unit switchMove (_endpoints # _currentIndex);

                _activeGesture = _gestures # _currentIndex;

                if !(_activeGesture isEqualTo "") then {
                    _unit switchGesture [_activeGesture,0,1,false];
                };
            } else {
                switch (_wantedIndex) do {
                    case 0: {
                        if (_height >= 0.16) then {
                            _wantedIndex = 2;
                        };
                    };

                    case 2: {
                        if (_height <= 0.12) then {
                            _wantedIndex = 0;
                        } else {
                            if (_height >= 0.46) then {
                                _wantedIndex = 4;
                            };
                        };
                    };

                    case 4: {
                        if (_height <= 0.42) then {
                            _wantedIndex = 2;
                        } else {
                            if (_height >= 0.75) then {
                                _wantedIndex = 5;
                            };
                        };
                    };

                    case 5: {
                        if (_height <= 0.71) then {
                            _wantedIndex = 4;
                        } else {
                            if (_height >= 0.96) then {
                                _wantedIndex = 6;
                            };
                        };
                    };

                    case 6: {
                        if (_height <= 0.92) then {
                            _wantedIndex = 5;
                        } else {
                            if (_height >= 0.99 && {_splay >= 0.99}) then {
                                _wantedIndex = 7;
                            };
                        };
                    };

                    case 7: {
                        if (_height < 0.97 || {_splay < 0.97}) then {
                            _wantedIndex = 6;
                        };
                    };

                    default {
                        _wantedIndex = [_height, _splay] call _getRawTarget;
                    };
                };

                if (_transitionActive) then {
                    if (diag_tickTime >= _transitionEnd) then {
                        _currentIndex = _transitionNextIndex;

                        _unit switchMove (_endpoints # _currentIndex);

                        private _nextGesture = _gestures # _currentIndex;

                        if !(_nextGesture isEqualTo "") then {
                            _activeGesture = _nextGesture;
                            _unit switchGesture [_activeGesture,0,1,false];
                        };

                        _transitionActive = false;
                        _transitionEnd = 0;
                        _transitionNextIndex = -1;
                    };
                } else {
                    if (_currentIndex != _wantedIndex) then {
                        private _direction = if (_wantedIndex > _currentIndex) then {1} else {-1};

                        private _transition = if (_direction > 0) then {
                            _downTransitions # _currentIndex
                        } else {
                            _upTransitions # _currentIndex
                        };

                        private _nextIndex = _currentIndex + _direction;

                        if (_transition isEqualTo "") then {
                            _currentIndex = _nextIndex;

                            _unit switchMove (_endpoints # _currentIndex);

                            private _nextGesture = _gestures # _currentIndex;

                            if !(_nextGesture isEqualTo "") then {
                                _activeGesture = _nextGesture;
                                _unit switchGesture [_activeGesture,0,1,false];
                            };
                        } else {
                            private _cfg = configFile >> "CfgMovesMaleSdr" >> "States" >> _transition;
                            private _speed = getNumber (_cfg >> "speed");

                            private _duration = if (_speed < 0) then {
                                -_speed
                            } else {
                                0.35
                            };

                            _unit switchMove _transition;

                            if !(_activeGesture isEqualTo "") then {
                                _unit switchGesture [_activeGesture,0,1,false];
                            };

                            _transitionNextIndex = _nextIndex;
                            _transitionEnd = diag_tickTime + _duration;
                            _transitionActive = true;
                        };
                    };
                };
            };

            missionNamespace setVariable ["UKSF_Recon_spotterCurrentIndex", _currentIndex];
            missionNamespace setVariable ["UKSF_Recon_spotterWantedIndex", _wantedIndex];

            sleep 0.01;
        };
    };
};