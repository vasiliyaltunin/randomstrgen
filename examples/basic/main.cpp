/**
 * @file main.cpp
 * @author Василий Алтунин (skyr@altuninvv.ru)
 * @brief Файл содержит пример использования класса TranslitCyrLat:
 * @version 0.1.0
 * @date 2026-01-14
 *
 * @copyright Алтунин Василий 2025
 *
 * Выводит транслитерированную строку и предбразованые в логин ФИО в консоль
 *
 */

#include <iostream>
#include <string>

#include <clocale>

#include <fcntl.h>
#include <io.h>

#include "../../include/randomstringgenerator/randomstringgenerator.h"

using namespace altuninvv::string;

int main(int argc, char *argv[]) {

   RandomStringGenerator rGen = RandomStringGenerator("OoIil1!|", false);

   std::cout << rGen.getRandomStr(12);

  return 0;
}
