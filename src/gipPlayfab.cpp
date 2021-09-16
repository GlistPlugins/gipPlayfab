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

void gipPlayfab::setTitleID(const std::string& titleID) {
	this->titleID = titleID;
	PlayFabSettings::staticSettings->titleId = titleID;
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

void gipPlayfab::OnStartGameSuccess(const StartGameResult& result, void* customData) {
	gLogi("gipPlayfab") << "Succesfully started a game with the id: " << result.LobbyID;
}

void gipPlayfab::OnLoginSuccess(const LoginResult& result, void* customData) {
	gLogi("gipPlayfab") << "Login successful.";
	finished = true;
}

void gipPlayfab::OnRegisterSuccess(const RegisterPlayFabUserResult& result, void* customData) {
	gLogi("gipPlayfab") << "Register Success usr: " << result.Username << " id: " << result.PlayFabId;
}

void gipPlayfab::OnRequestFail(const PlayFabError& error, void* customData) {

	RequestData* action = (RequestData*)customData;

	gLogi("gipPlayfab") << "Something went wrong with " << action->requestname << std::endl;
	gLogi("gipPlayfab") << "Here's some debug information:\n";
	gLogi("gipPlayfab") << error.GenerateErrorReport();

	delete action;
}
