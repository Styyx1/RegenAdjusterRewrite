#pragma once

namespace Hooks
{
	void InstallHooks();

	class PlayerUpdate
	{
	public:
		static void UpdateLoopPlayer(RE::PlayerCharacter* p, float a_delta);
		static void Install();
	private:
		static inline REL::Relocation<decltype(&UpdateLoopPlayer)> func;
	};

	class NPCUpdate
	{
	public:
		static void UpdateLoopNPC(RE::Character* a_this, float a_delta);
		static void Install();
	private:
		static inline REL::Relocation<decltype(&UpdateLoopNPC)> func;
	};
}
