Scriptname regenAdjusterMCM extends MCM_ConfigBase

Function LoadSettings()
    RegenAdjuster.UpdateSettings()
    if(RegenAdjuster.ShouldApplyGameSettings())
        RegenAdjuster.ApplyGameSettings()
    endif
endfunction

Event OnConfigInit()
    RegenAdjuster.UpdateSettings()
    if(RegenAdjuster.ShouldApplyGameSettings())
        RegenAdjuster.ApplyGameSettings()
    endif
EndEvent

Event OnSettingChange(string a_ID)
    self.RefreshMenu()
    RegenAdjuster.UpdateSettings()
    if(RegenAdjuster.ShouldApplyGameSettings())
        RegenAdjuster.ApplyGameSettings()
    endif
endevent

