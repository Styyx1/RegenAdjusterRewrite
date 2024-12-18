-- set minimum xmake version
set_xmakever("2.8.2")

-- includes
includes("lib/commonlibsse")

-- set project
set_project("regen-adjuster-re")
set_version("1.0.0")
set_license("GPL-3.0")

-- set defaults
set_languages("c++23")
set_warnings("allextra")

-- add rules
add_rules("mode.debug", "mode.releasedbg")
add_rules("plugin.vsxmake.autoupdate")
set_defaultmode("releasedbg")


-- set policies
set_policy("package.requires_lock", true)

-- set configs
set_config("skyrim_ae", true)
set_config("rex_ini", true)

-- targets
target("regen-adjuster-re")
    -- add dependencies to target
    add_deps("commonlibsse")
    if has_config("skyrim_ae") then
        set_targetdir("/build/SkyrimAE/skse/plugins")
    else
        set_targetdir("/build/SkyrimSE/skse/plugins")
    end 
    -- add commonlibsse plugin
    add_rules("commonlibsse.plugin", {
        name = "regen-adjuster-re",
        author = "styyx",
        description = "rewrite of regen adjuster"
    })

    -- add src files
    add_files("src/**.cpp")
    add_headerfiles("src/**.h")
    add_includedirs("src")
    set_pcxxheader("src/pch.h")

add_extrafiles("release/**.ini")
add_extrafiles("papyrus/**.psc")
add_extrafiles("papyrus/**.pex")

after_build(function(target)
    local copy = function(env, ext)
        for _, env in pairs(env:split(";")) do
            if os.exists(env) then
                local plugins = path.join(env, ext, "SKSE/Plugins")
                local dataSource = path.join(env, ext, "Source/Scripts")
                local dataScripts = path.join(env, ext, "Scripts")
                os.mkdir(plugins)
                os.trycp(target:targetfile(), plugins)
                os.trycp(target:symbolfile(), plugins)
                os.trycp("$(projectdir)/papyrus/**.psc", dataSource)
                os.trycp("$(projectdir)/papyrus/**.pex", dataScripts)
            end
        end
    end
    if os.getenv("XSE_TES5_MODS_PATH") then
        copy(os.getenv("XSE_TES5_MODS_PATH"), target:name())
    elseif os.getenv("XSE_TES5_GAME_PATH") then
        copy(os.getenv("XSE_TES5_GAME_PATH"), "Data")
    end
end)