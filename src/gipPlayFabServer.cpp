/*
 * gipPlayFabServer.cpp
 *
 *  Created on: 16 Eyl 2021
 *      Author: kayra
 */

#include <gipPlayFabServer.h>

gipPlayFabServer::gipPlayFabServer() {
	// TODO Auto-generated constructor stub

}

gipPlayFabServer::~gipPlayFabServer() {
	// TODO Auto-generated destructor stub
}

void gipPlayFabServer::registerGame() {
}

void gipPlayFabServer::OnRegisterGameSuccess(const RegisterGameResponse &response, void *customData) {
	gLogi("playfab server") << response.LobbyId << " created successfully!";
}

void gipPlayFabServer::OnRegisterGameFail(const PlayFabError &error, void *customData) {
	gLogi("playfab server") << "There was an error while creating the server:";
	gLogi("playfab server") << error.GenerateErrorReport();
}
