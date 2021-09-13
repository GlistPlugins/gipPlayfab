cmake_minimum_required (VERSION 3.10.2)

##### PLUGIN NAME #####
set(pluginname gipPlayfab)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(PREBUILT_DIR ${PLUGIN_DIR}/prebuilts)


##### PLUGIN SOURCES #####
list(APPEND PLUGIN_SRCS
			${PLUGIN_DIR}/src/gipPlayfab.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabAdminApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabAdminInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabApiSettings.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabAuthenticationApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabAuthenticationContext.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabAuthenticationInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabCallRequestContainer.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabCallRequestContainerBase.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabClientApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabClientInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabCloudScriptApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabCloudScriptInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabCurlHttpPlugin.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabDataApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabDataInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabError.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabEvent.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabEventApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabEventBuffer.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabEventPipeline.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabEventRouter.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabEventsApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabEventsInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabExperimentationApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabExperimentationInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabGroupsApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabGroupsInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabInsightsApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabInsightsInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabIXHR2HttpPlugin.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabIXHR2HttpRequest.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabLocalizationApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabLocalizationInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabMatchmakerApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabMatchmakerInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabMultiplayerApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabMultiplayerInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabPluginManager.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabProfilesApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabProfilesInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabServerApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabServerInstanceApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabSettings.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabSpinLock.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/PlayFabWinHttpPlugin.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/QoS/PlayFabQoSApi.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/QoS/QoSSocket.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/QoS/RegionResult.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/source/playfab/QoS/XPlatSocket.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/stdafx.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/external/jsoncpp/src/lib_json/json_reader.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/external/jsoncpp/src/lib_json/json_tool.h
			${PLUGIN_DIR}/libraries/XPlatCppSdk/external/jsoncpp/src/lib_json/json_value.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/external/jsoncpp/src/lib_json/json_valueiterator.inl
			${PLUGIN_DIR}/libraries/XPlatCppSdk/external/jsoncpp/src/lib_json/json_writer.cpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/external/jsoncpp/src/lib_json/version.h.in
)


##### PLUGIN HEADERS #####
list(APPEND PLUGIN_INCLUDES
			${PLUGIN_DIR}/src
			${PREBUILT_DIR}/include
			${PLUGIN_DIR}/libraries/XPlatCppSdk/external
			${PLUGIN_DIR}/libraries/XPlatCppSdk/external/jsoncpp
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code/include
			${PLUGIN_DIR}/libraries/XPlatCppSdk/code
)


##### PLUGIN DEPENDENCY LOCATIONS (IF ANY) #####
if(WIN32)
	list(APPEND PLUGIN_LINKDIRS
				${PREBUILT_DIR}/lib/win32
				${PREBUILT_DIR}/bin
	)
	
	#set(PLUGIN_LIBDIRS ${PREBUILT_DIR}/lib/win32)
	list(APPEND PLUGIN_LIBDIRS
				${PREBUILT_DIR}/lib/win32
	)
elseif(LINUX)
	#Linux libs here
elseif(APPLE)
	#Macos libs here
endif(WIN32)


##### PLUGIN DEPENDENCY LINKING (IF ANY) #####					
if(WIN32)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
				winhttp
				ws2_32
	)
elseif(LINUX)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
	)
elseif(APPLE)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
	)
endif(WIN32)
