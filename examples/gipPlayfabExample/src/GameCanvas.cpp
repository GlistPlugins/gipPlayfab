/*
 * GameCanvas.cpp
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */


#include "GameCanvas.h"

std::string username;
std::string email;
std::string password;
std::string displayName;
int GiveUpAfterSeconds;

GameCanvas::GameCanvas(gApp* root) : gBaseCanvas(root) {
	this->root = root;
	username = "";
	email = "";
	password = "";
	displayName = "";
	GiveUpAfterSeconds = 120;

}

GameCanvas::~GameCanvas() {
}

void GameCanvas::setup() {
	pf.registerPlayFabAccount(username, email, password, displayName); //This only has to run once per player account
	pf.login(username, password);
	pf.createMatchmakingTicket(GiveUpAfterSeconds);
	pf.checkMatchmakingTicket(pf.getTicketId());
	logo.loadImage("glistengine_logo.png");
}

void GameCanvas::update() {
}

void GameCanvas::draw() {
	logo.draw((getWidth() - logo.getWidth()) / 2, (getHeight() - logo.getHeight()) / 2);
}

void GameCanvas::keyPressed(int key) {
//	gLogi("GameCanvas") << "keyPressed:" << key;
}

void GameCanvas::keyReleased(int key) {
//	gLogi("GameCanvas") << "keyReleased:" << key;
}

void GameCanvas::charPressed(unsigned int codepoint) {
//	gLogi("GameCanvas") << "charPressed:" << gCodepointToStr(codepoint);
}

void GameCanvas::mouseMoved(int x, int y) {
//	gLogi("GameCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void GameCanvas::mouseDragged(int x, int y, int button) {
//	gLogi("GameCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void GameCanvas::mousePressed(int x, int y, int button) {
}

void GameCanvas::mouseReleased(int x, int y, int button) {
//	gLogi("GameCanvas") << "mouseReleased" << ", button:" << button;
}

void GameCanvas::mouseScrolled(int x, int y) {
//	gLogi("GameCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
}

void GameCanvas::mouseEntered() {
}

void GameCanvas::mouseExited() {
}

void GameCanvas::windowResized(int w, int h) {
}

void GameCanvas::showNotify() {

}

void GameCanvas::hideNotify() {

}

