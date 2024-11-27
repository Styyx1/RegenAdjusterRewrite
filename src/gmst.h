#pragma once
#include "Settings.h"

using namespace Settings::Values;

namespace GMST {

	static bool SetGMST(const char* a_setting, float a_set) {

		if (auto set = RE::GameSettingCollection::GetSingleton()) {
			if (auto setting = set->GetSetting(a_setting)) {
				setting->data.f = a_set;
				return true;
			} else {
				logs::info("Invalid GMST ptr");
				return false;
			}
		} else {
			logs::info("Invalid SettingCollection ptr");
			return false;
		}
	};
	static void SetSettings()
	{
		logs::info("Changing game settings...");
		SetGMST("fCombatMagickaRegenRateMult", fCombatMagickaRate.GetValue());
		SetGMST("fCombatStaminaRegenRateMult", fCombatStaminaRate.GetValue());

		SetGMST("fPowerAttackStaminaPenalty", fPowerAttackStaminaPenalty.GetValue());

		SetGMST("fSprintStaminaDrainMult", fSprintStaminaDrainMult.GetValue());
		SetGMST("fSprintStaminaWeightBase", fSprintStaminaWeightBase.GetValue());
		SetGMST("fSprintStaminaWeightMult", fSprintStaminaWeightMult.GetValue());

		SetGMST("fHealthRegenDelayMax", fHealthRegenDelay.GetValue());
		SetGMST("fDamagedHealthRegenDelay", fDmgHealthRegenDelay.GetValue());

		SetGMST("fStaminaRegenDelayMax", fStaminaRegenDelay.GetValue());
		SetGMST("fDamagedStaminaRegenDelay", fDmgStaminaRegenDelay.GetValue());

		SetGMST("fMagickaRegenDelayMax", fMagickaRegenDelay.GetValue());
		SetGMST("fDamagedMagickaRegenDelay", fDmgMagickaRegenDelay.GetValue());

		SetGMST("fOutOfBreathStaminaRegenDelay", fOutOfBreath.GetValue());
		logs::info("...Game settings changed");
	}
};