#pragma once

namespace Settings
{
    namespace Values
    {
        static REX::INI::F32 fHealRate{ "Base", "fHealRate", -1.00f };
        static REX::INI::F32 fStaminaRate{"Base", "fStaminaRate", -1.00f};
        static REX::INI::F32 fMagickaRate{ "Base", "fMagickaRate", -1.00f };

        static REX::INI::F32 fHealthRegenDelay{ "GameSettings", "fHealthRegenDelayMax", -1.00f };
        static REX::INI::F32 fDmgHealthRegenDelay{ "GameSettings", "fDamagedHealthRegenDelay", -1.00f };

        static REX::INI::F32 fStaminaRegenDelay{"GameSettings", "fStaminaRegenDelayMax", -1.00f};
        static REX::INI::F32 fDmgStaminaRegenDelay{"GameSettings", "fDamagedStaminaRegenDelay", -1.00f};

        static REX::INI::F32 fMagickaRegenDelay{"GameSettings", "fMagickaRegenDelayMax", -1.00f};
        static REX::INI::F32 fDmgMagickaRegenDelay{"GameSettings", "fDamagedMagickaRegenDelay", -1.00f};

        static REX::INI::F32 fPowerAttackStaminaPenalty{"GameSettings", "fPowerAttackStaminaPenalty", -1.00f};

        static REX::INI::F32 fSprintStaminaDrainMult{"GameSettings", "fSprintStaminaDrainMult", -1.00f};
        static REX::INI::F32 fSprintStaminaWeightBase{"GameSettings", "fSprintStaminaWeightBase", -1.00f};
        static REX::INI::F32 fSprintStaminaWeightMult{"GameSettings", "fSprintStaminaWeightMult", -1.00f};

        static REX::INI::F32 fOutOfBreath{"GameSettings", "fOutOfBreathStaminaRegenDelay", -1.00f};

        static REX::INI::F32 fCombatStaminaRate{"GameSettings", "fCombatStaminaRateMult", -1.00f};
        static REX::INI::F32 fCombatMagickaRate{"GameSettings", "fCombatMagickaRateMult", -1.00f};

        static REX::INI::F32 fIdleHealRate{"Conditions", "fSneakHealRate", -1.00f};
        static REX::INI::F32 fIdleStaminaRate{"Conditions", "fSneakStaminaRate", -1.00f};
        static REX::INI::F32 fIdleMagickaRate{"Conditions", "fSneakMagickaRate", -1.00f};

        static REX::INI::F32 fRunHealRate{"Conditions", "fRunHealRate", -1.00f};
        static REX::INI::F32 fRunStaminaRate{"Conditions", "fRunStaminaRate", -1.00f};
        static REX::INI::F32 fRunMagickaRate{"Conditions", "fRunMagickaRate", -1.00f};

        static REX::INI::F32 fBlockHealRate{"Conditions", "fBlockHealRate", -1.00f};
        static REX::INI::F32 fBlockStaminaRate{"Conditions", "fBlockStaminaRate", -1.00f};
        static REX::INI::F32 fBlockMagickaRate{"Conditions", "fBlockMagickaRate", -1.00f};

        static REX::INI::F32 fSprintHealRate{"Conditions", "fSprintHealRate", -1.00f};
        static REX::INI::F32 fSprintMagickaRate{"Conditions", "fSprintMagickaRate", -1.00f};

        static REX::INI::F32 fSwimHealRate{"Conditions", "fSwimHealRate", -1.00f};
        static REX::INI::F32 fSwimStaminaRate{"Conditions", "fSwimStaminaRate", -1.00f};
        static REX::INI::F32 fSwimMagickaRate{"Conditions", "fSwimMagickaRate", -1.00f};

        static REX::INI::F32 fCombatHealRate{"Conditions", "fCombatHealRateMult", -1.00f};       

        static REX::INI::F32 fMidAirHealRate{ "Conditions", "fMidAirHealRate", -1.00f };
        static REX::INI::F32 fMidAirStaminaRate{ "Conditions", "fMidAirStaminaRate", -1.00f };
        static REX::INI::F32 fMidAirMagickaRate{ "Conditions", "fMidAirMagickaRate", -1.00f };

        static REX::INI::Bool bExcludeDragons{ "Toggles", "bExcludeDragons", false };
        static REX::INI::Bool bOnlyPlayer{ "Toggles", "bOnlyPlayer", false };
        static REX::INI::Bool bOnlyHumanoids{ "Toggles", "bOnlyHumanoids", false };
        static REX::INI::Bool bExcludePlayer{ "Toggles", "bExcludePlayer", false };
        static REX::INI::Bool bUseRaceFlag{ "Toggles", "bUseRaceFlag", false };
        static REX::INI::Bool bChangeGameSettings{ "Toggles", "bChangeGameSettings", true };
    }

    static void Update()
    {
        logs::info("Loading settings...");
        const auto ini = REX::INI::SettingStore::GetSingleton();
        ini->Init("Data/MCM/Config/regenadjuster/settings.ini", "Data/MCM/Settings/regenadjuster.ini");
        ini->Load();
        logs::info("...Settings loaded");
    }
}
// Credits: https://github.com/shad0wshayd3-TES5/BakaBloodMagic/blob/main/src/BloodMagic/Settings.h