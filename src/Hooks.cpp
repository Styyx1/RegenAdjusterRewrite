#include "Hooks.h"
#include "gmst.h"
#include "Settings.h"

using namespace GMST;
using namespace Settings::Values;

namespace Hooks
{
	void PlayerUpdate::UpdateLoopPlayer(RE::PlayerCharacter* p, float a_delta)
	{
		p->SetActorValue(RE::ActorValue::kCombatHealthRegenMultiply, fCombatHealRate.GetValue());
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

		float h_rate = fHealRate.GetValue(), s_rate = fStaminaRate.GetValue(), m_rate = fMagickaRate.GetValue();

		if (p->IsSneaking()) {
			h_rate = fIdleHealRate.GetValue(), s_rate = fIdleStaminaRate.GetValue(), m_rate = fIdleMagickaRate.GetValue();
		}
		if (p->IsRunning()) {
			h_rate = fRunHealRate.GetValue(), s_rate = fRunStaminaRate.GetValue(), m_rate = fRunMagickaRate.GetValue();
		}
		if (p->actorState2.wantBlocking) {
			h_rate = fBlockHealRate.GetValue(), s_rate = fBlockStaminaRate.GetValue(), m_rate = fBlockMagickaRate.GetValue();
		}
		if (p->IsSprinting()) {
			h_rate = fSprintHealRate.GetValue(), m_rate = fSprintMagickaRate.GetValue();
		}
		if (p->IsSwimming()) {
			h_rate = fSwimHealRate.GetValue(), s_rate = fSwimStaminaRate.GetValue(), m_rate = fSwimMagickaRate.GetValue();
		}

		p->SetActorValue(RE::ActorValue::kHealRate, h_rate);
		p->SetActorValue(RE::ActorValue::kStaminaRate, s_rate);
		p->SetActorValue(RE::ActorValue::kMagickaRate, m_rate);
		func(p, a_delta);
	}
	void PlayerUpdate::Install()
	{
		REL::Relocation<std::uintptr_t> PlayerVTBL{ RE::VTABLE_PlayerCharacter[0] };
		func = PlayerVTBL.write_vfunc(0xAD, UpdateLoopPlayer);
		logs::info("hook:Player Update");
	}

	void NPCUpdate::UpdateLoopNPC(RE::Character* a_this, float a_delta)
	{
		float h_rate = fHealRate.GetValue(), s_rate = fStaminaRate.GetValue(), m_rate = fMagickaRate.GetValue();

		if (a_this->IsSneaking()) {
			h_rate = fIdleHealRate.GetValue(), s_rate = fIdleStaminaRate.GetValue(), m_rate = fIdleMagickaRate.GetValue();
		}
		if (a_this->IsRunning()) {
			h_rate = fRunHealRate.GetValue(), s_rate = fRunStaminaRate.GetValue(), m_rate = fRunMagickaRate.GetValue();
		}
		if (a_this->actorState2.wantBlocking) {
			h_rate = fBlockHealRate.GetValue(), s_rate = fBlockStaminaRate.GetValue(), m_rate = fBlockMagickaRate.GetValue();
		}
		if (a_this->IsSprinting()) {
			h_rate = fSprintHealRate.GetValue(), m_rate = fSprintMagickaRate.GetValue();
		}
		if (a_this->IsSwimming()) {
			h_rate = fSwimHealRate.GetValue(), s_rate = fSwimStaminaRate.GetValue(), m_rate = fSwimMagickaRate.GetValue();
		}

		a_this->SetActorValue(RE::ActorValue::kHealRate, h_rate);
		a_this->SetActorValue(RE::ActorValue::kStaminaRate, s_rate);
		a_this->SetActorValue(RE::ActorValue::kMagickaRate, m_rate);

		func(a_this, a_delta);
	}
	void NPCUpdate::Install()
	{
		REL::Relocation<std::uintptr_t> ActorVTABLE{ RE::VTABLE_Character[0] };
		func = ActorVTABLE.write_vfunc(0xAD, UpdateLoopNPC);
		logs::info("hook:NPC Update");
	}
	void InstallHooks()
	{
		PlayerUpdate::Install();
		NPCUpdate::Install();
	}
}

