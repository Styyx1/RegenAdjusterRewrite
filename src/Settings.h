#pragma once

namespace Settings
{
    namespace Values
    {
        static REX::INI::F32 fHealRate{ "Base", "fHealRate", -1.00f };
        static REX::INI::F32 fStaminaRate{"Base", "fStaminaRate", -1.00f};
        static REX::INI::F32 fMagickaRate{ "Base", "fMagickaRate", -1.00f };

        static REX::INI::F32 fHealthRegenDelay{ "Base", "fHealthRegenDelayMax", -1.00f };
        static REX::INI::F32 fDmgHealthRegenDelay{ "Base", "fDamagedHealthRegenDelay", -1.00f };

        static REX::INI::F32 fStaminaRegenDelay{"Base", "fStaminaRegenDelayMax", -1.00f};
        static REX::INI::F32 fDmgStaminaRegenDelay{"Base", "fDamagedStaminaRegenDelay", -1.00f};

        static REX::INI::F32 fMagickaRegenDelay{"Base", "fMagickaRegenDelayMax", -1.00f};
        static REX::INI::F32 fDmgMagickaRegenDelay{"Base", "fDamagedMagickaRegenDelay", -1.00f};

        static REX::INI::F32 fPowerAttackStaminaPenalty{"Base", "fPowerAttackStaminaPenalty", -1.00f};

        static REX::INI::F32 fSprintStaminaDrainMult{"Base", "fSprintStaminaDrainMult", -1.00f};
        static REX::INI::F32 fSprintStaminaWeightBase{"Base", "fSprintStaminaWeightBase", -1.00f};
        static REX::INI::F32 fSprintStaminaWeightMult{"Base", "fSprintStaminaWeightMult", -1.00f};

        static REX::INI::F32 fOutOfBreath{"Base", "fOutOfBreathStaminaRegenDelay", -1.00f};

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
        static REX::INI::F32 fCombatStaminaRate{"Conditions", "fCombatStaminaRateMult", -1.00f};
        static REX::INI::F32 fCombatMagickaRate{"Conditions", "fCombatMagickaRateMult", -1.00f};

        static REX::INI::F32 fMidAirHealRate{ "Conditions", "fMidAirHealRate", -1.00f };
        static REX::INI::F32 fMidAirStaminaRate{ "Conditions", "fMidAirStaminaRate", -1.00f };
        static REX::INI::F32 fMidAirMagickaRate{ "Conditions", "fMidAirMagickaRate", -1.00f };

        static REX::INI::Bool bExcludeDragons{ "Toggles", "bExcludeDragons", false };

    }    

    static void Update()
    {
        const auto ini = REX::INI::SettingStore::GetSingleton();
        ini->Init("Data/SKSE/Plugins/regen-adjuster.ini", "Data/SKSE/Plugins/regen-adjuster-custom.ini");
        ini->Load();
    }

}