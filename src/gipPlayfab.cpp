/*
 * gipPlayfab.cpp
 *
 *  Created on: 13 Sep 2021
 *      Author: noyan
 */

#include "gipPlayfab.h"

bool gipPlayfab::finished = false;

gipPlayfab::gipPlayfab() {}

gipPlayfab::~gipPlayfab() {}

void gipPlayfab::setTitleID(const std::string& titleID, const std::string& secretkey) {
	PlayFabSettings::staticSettings->titleId = titleID;
	PlayFabSettings::staticSettings->developerSecretKey = secretkey;
}

void gipPlayfab::registerPlayFabAccount(const std::string& username, const std::string& email, const std::string& password, const std::string& displayName) {
	RegisterPlayFabUserRequest request;
	request.DisplayName = displayName;
	request.Email = email;
	request.Password = password;
	request.Username = username;

	RequestData* action = new RequestData;
	action->requestname = "RegisterPlayFabUser";

	PlayFabClientAPI::RegisterPlayFabUser(request, OnRegisterSuccess, OnRequestFail, action);
}

void gipPlayfab::login(const std::string& username, const std::string& password) {

	LoginWithPlayFabRequest request;
	request.Username = username;
	request.Password = password;

	RequestData* action = new RequestData;
	action->requestname = "LoginWithPlayfab";

	PlayFabClientAPI::LoginWithPlayFab(request, OnLoginSuccess, OnRequestFail, action);
}

void gipPlayfab::update() {
	if(PlayFabClientAPI::Update() != 0) return;
}

void gipPlayfab::openLobby() {
	StartGameRequest request;
	request.BuildVersion = "1";
	request.GameMode = "0";
	request.pfRegion = Region::RegionEUWest;

	RequestData* action = new RequestData;
	action->requestname = "StartGame";

	PlayFabClientAPI::StartGame(request, OnStartGameSuccess, OnRequestFail, action);
}

void gipPlayfab::addServerBuild() {
	AdminModels::AddServerBuildRequest request;
	request.BuildId = "02111999";
	request.MaxGamesPerHost = 2;
	request.MinFreeGameSlots = 10;

	RequestData* action = new RequestData;
	action->requestname = "AddServerBuild";

	PlayFabAdminAPI::AddServerBuild(request, OnAddServerBuildSuccess, OnRequestFail, action);
}

void gipPlayfab::OnStartGameSuccess(const StartGameResult& result, void* customData) {
	gLogi("gipPlayfab") << "Succesfully started a game with the id: " << result.LobbyID;
}

void gipPlayfab::OnLoginSuccess(const LoginResult& result, void* customData) {
	GetPlayerProfileRequest request;
	request.PlayFabId = result.PlayFabId;

	std::string* displayname = new std::string();

	PlayFabClientAPI::GetPlayerProfile(request, OnGetPlayerProfileSuccess, OnRequestFail, displayname);

	gLogi("gipPlayfab") << "Succesfully logged in player " << *displayname;
	finished = true;
}

void gipPlayfab::OnRegisterSuccess(const RegisterPlayFabUserResult& result, void* customData) {
	gLogi("gipPlayfab") << "Register Success usr: " << result.Username << " id: " << result.PlayFabId;
}

void gipPlayfab::OnGetPlayerProfileSuccess(const GetPlayerProfileResult& result, void* customData) {

	std::string* playername = (std::string*)customData;

	playername->append(result.PlayerProfile->DisplayName);

	gLogi("profile") << *playername;
}

void gipPlayfab::OnAddServerBuildSuccess(const AdminModels::AddServerBuildResult& result, void* customData) {

	gLogi("buraya 2");
	gLogi("Build result") << "build id: " << result.BuildId;
	gLogi("buraya 3");
}

void gipPlayfab::OnRequestFail(const PlayFabError& error, void* customData) {

	RequestData* action = (RequestData*)customData;

	gLogi("gipPlayfab") << "Something went wrong with the Request: " << action->requestname << std::endl;
	gLogi("gipPlayfab") << "Here's some debug information:\n";
	gLogi("gipPlayfab") << error.GenerateErrorReport();

	delete action;
}
