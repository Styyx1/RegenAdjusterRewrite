#include "Hooks.h"
#include "gmst.h"
#include "Settings.h"

using namespace GMST;
using namespace Settings::Values;

// Hook player update loop and NPC update loop separately, so i can exclude one or the other more easily
namespace Hooks
{
	void PlayerUpdate::UpdateLoopPlayer(RE::PlayerCharacter* p, float a_delta)
	{
		NPCUpdate::ChangeStats(p);
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
		if (bExcludeDragons.GetValue()) {
			if (a_this->GetRace()->HasKeywordString("ActorTypeDragon")) {
				func(a_this, a_delta);
				return;
			}			
		}

		if (bOnlyHumanoids.GetValue()) {
			if (!a_this->GetRace()->HasKeywordString("ActorTypeDragon") && !a_this->GetRace()->HasKeywordString("ActorTypeUndead") && !a_this->GetRace()->HasKeywordString("ActorTypeCreature") && !a_this->GetRace()->HasKeywordString("ActorTypeAnimal")) {
				ChangeStats(a_this);
				func(a_this, a_delta);
				return;
			}
		}
		else {
			ChangeStats(a_this);
		}
		
		func(a_this, a_delta);
	}
	void NPCUpdate::Install()
	{
		REL::Relocation<std::uintptr_t> ActorVTABLE{ RE::VTABLE_Character[0] };
		func = ActorVTABLE.write_vfunc(0xAD, UpdateLoopNPC);
		logs::info("hook:NPC Update");
	}
	void NPCUpdate::ChangeStats(RE::Character* a_this)
	{
		a_this->SetActorValue(RE::ActorValue::kCombatHealthRegenMultiply, fCombatHealRate.GetValue());

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
		if (a_this->IsInMidair()) {
			h_rate = fMidAirHealRate.GetValue(), s_rate = fMidAirStaminaRate.GetValue(), m_rate = fMidAirMagickaRate.GetValue();
		}

		if (bUseRaceFlag.GetValue()) {
			if(!a_this->GetRace()->data.flags.any(RE::RACE_DATA::Flag::kRegenHPInCombat))
			{
				a_this->SetActorValue(RE::ActorValue::kCombatHealthRegenMultiply, 0.00f);
			}
		}		

		a_this->SetActorValue(RE::ActorValue::kHealRate, h_rate);
		a_this->SetActorValue(RE::ActorValue::kStaminaRate, s_rate);
		a_this->SetActorValue(RE::ActorValue::kMagickaRate, m_rate);
	}
	//only install hooks when the settings allow it. Makes it incompatible with mid game changes though
	void InstallHooks()
	{		
		if (!bExcludePlayer.GetValue()) {
			PlayerUpdate::Install();
		}		
		if (!bOnlyPlayer.GetValue()) {
			NPCUpdate::Install();
		}
	}
}

