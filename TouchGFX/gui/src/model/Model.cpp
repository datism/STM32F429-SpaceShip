#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <string.h>
#include "stm32f4xx_hal.h"

extern RTC_HandleTypeDef hrtc;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}

void Model::saveHighScore() {
	touchgfx::Unicode::UnicodeChar names[5][6];
	uint32_t points[5];
	uint8_t pos = -1;

	//Get names and points
	getHighScore(names, points);

	//Find if point > leaderboard points
	for (uint8_t i = 0; i < 5; ++i) {
		if(point > points[i]) {
			pos = i;
			break;
		}
	}

	if (pos == -1)
		return;


	//swap points
	for (int8_t i = 4; i >= pos; --i) {
		if (i == pos) {
			memcpy(names[i], name, 12);
			points[i] = point;
		}
		else {
			memcpy(names[i], names[i-1], 12);
			points[i] = points[i-1];
		}
	}

	//write rtc reg
	uint32_t temp;
	for (uint8_t i = pos; i < 5; i ++) {
		memcpy(&temp, names[i], 4);
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0 + i * 4, temp);
		memcpy(&temp, names[i] + 2, 4);
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0 + i * 4 + 1, temp);
		memcpy(&temp, names[i] + 4, 4);
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0 + i * 4 + 2, temp);

		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR0 + i * 4 + 3, points[i]);
	}
}

void Model::getHighScore(touchgfx::Unicode::UnicodeChar names[5][6], uint32_t points[5]) {

	uint32_t temp;

	for (uint8_t i = 0; i < 5; ++i) {
		//4 MSBs of name
		temp = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0 + i * 4);
		memcpy(names[i], &temp, 4);
		//4 middle bytes of name
		temp = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0 + i * 4 + 1);
		memcpy(names[i] + 2, &temp, 4);
		//4 LSBs of name
		temp = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0 + i * 4 + 2);
		memcpy(names[i] + 4, &temp, 4);
		//point
		points[i] =  HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0 + i * 4 + 3);
	}

}

void Model::getNames(touchgfx::Unicode::UnicodeChar names[5][6]) {
	uint32_t temp;
	for (uint8_t i = 0; i < 5; ++i) {
		temp = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0 + i * 4);
		memcpy(names[i], &temp, 4);
		temp = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0 + i * 4 + 1);
		memcpy(names[i] + 2, &temp, 4);
		temp = HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0 + i * 4 + 2);
		memcpy(names[i] + 4, &temp, 4);
	}
}

void Model::getPoints(uint32_t points[5]) {
	for (uint8_t i = 0; i < 5; ++i) {
		points[i] =  HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0 + i * 4 + 3);
	}
}

void Model::updateName(touchgfx::Unicode::UnicodeChar n[6]) {
	touchgfx::Unicode::strncpy(name, n, 6);
}

void Model::updatePoint(uint32_t p) {
	point = p;
}
