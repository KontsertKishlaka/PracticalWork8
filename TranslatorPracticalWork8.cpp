#include <iostream>
#include <map>
#include <string>

using namespace std;

void printInterface();
void printRussianWordList();
void printEnglishWordList();
void inputOutputTranslation(char from);
void checkProgramContinue();

bool _isProgramStop = false;

map <string, string> _wordDictionary = {
	{ "Serendipity", "Cлучайное счастливое открытие" },
	{ "Ephemeral", "Кратковременный, мимолетный" },
	{ "Mellifluous", "Мелодичный, приятный для слуха" },
	{ "Ubiquitous", "Вездесущий, повсеместный" },
	{ "Quixotic", "Мечтательный, идеалистический, непрактичный" },
	{ "Petrichor", "Запах земли после дождя" },
	{ "Schadenfreude", "Злорадство, удовольствие от чужой беды" },
	{ "Sonder", "Осознание того, что каждый незнакомец имеет свою собственную, сложную и интересную жизнь" },
	{ "Hibernal", "Зимний, относящийся к зиме" },
	{ "Labyrinthine", "Лабиринтный, запутанный" },
	{ "Stunning", "Потрясающий" },
	{ "Wistful", "Тоскующий, грустный, полный сожаления" },
	{ "Indelible", "Неизгладимый, вечный" },
	{ "Ethereal", "Неземной, небесный, воздушный" },
	{ "Zeitgeist", "Дух времени, общественное настроение" }
};


void printInterface() {
	cout << "[+] Переводчик\n\n[1] \x1b[91mАнглийские\x1b[0m слова.\n[2] \x1b[94mРусские\x1b[0m слова.\n\n[3] Выйти из программы.\n\n";

	char userChoice;
	cin >> userChoice;

	while (userChoice == '1' || userChoice == '2' || userChoice == '3') {
		system("cls");

		switch (userChoice)
		{
		case '1': {
			printEnglishWordList();
			inputOutputTranslation('e');
			return;
		}
		case '2': {
			printRussianWordList();
			inputOutputTranslation('r');
			return;
		}
		case '3': {
			_isProgramStop = true;
			return;
		}
		default:
			cout << "\x1b[91mВведён некорректный номер операции!\x1b[0m Повторите ввод.";
			break;
		}
	}
}


void printRussianWordList() {
	cout << "[+] Список \x1b[94mрусских\x1b[0m слов:\n\n";

	short i = 1;
	for (auto const& kv: _wordDictionary) {
		cout << "[" << i << "] " << kv.second << "\n";
		i++;
	}

	cout << "\n";
}


void printEnglishWordList() {
	cout << "[+] Список \x1b[91mанглийских\x1b[0m слов:\n\n";

	short i = 1;
	for (auto const& kv : _wordDictionary) {
		cout << "[" << i << "] " << kv.first << "\n";
		i++;
	}

	cout << "\n";
}


void inputOutputTranslation(char from) {
	switch (from)
	{
	case 'r': {
		cout << "[+] Выберите номер \x1b[94mрусского\x1b[0m слова: ";
		short wordChoice;
		cin >> wordChoice;

		system("cls");

		if (wordChoice > 0 && wordChoice <= _wordDictionary.size()) {
			auto it = _wordDictionary.begin();
			advance(it, wordChoice - 1);
			cout << "[+] Перевод: \x1b[94m" << it->second << "\x1b[0m -> \x1b[91m" << it->first << "\x1b[0m\n";
		}
		else
			cout << "\x1b[91mНеверный номер слова.\x1b[0m\n";
		break;
	}
	case 'e': {
		cout << "[+] Выберите номер \x1b[91mанглийского\x1b[0m слова: ";
		short wordChoice;
		cin >> wordChoice;

		system("cls");

		if (wordChoice > 0 && wordChoice <= _wordDictionary.size()) {
			auto it = _wordDictionary.begin();
			advance(it, wordChoice - 1);
			cout << "[+] Перевод: \x1b[91m" << it->first << "\x1b[0m -> \x1b[94m" << it->second << "\x1b[0m\n";
		}
		else
			cout << "\x1b[91mНеверный номер слова.\x1b[0m\n";
		break;
	}
	default:
		cout << "\x1b[91mВ словаре нет такого языка.\x1b[0m\n";
		break;
	}
}


void checkProgramContinue() { 
	cout << "\n\nПродолжаем переводить? (Введите \x1b[92m\"+\"\x1b[0m, если \x1b[92mхотите продолжить\x1b[0m или \x1b[91m\"-\"\x1b[0m, чтобы \x1b[91mзавершить программу\x1b[0m.)\n\n";

	char userChoice;
	cin >> userChoice;

	while (userChoice == '+' || userChoice == '-')
	{
		switch (userChoice) {
		case '+': {
			system("cls");
			return;
		}
		case '-':
			_isProgramStop = true;
			return;
		default: {
			cout << "\x1b[91mВведён некорректный оператор!\x1b[0m Повторите ввод.";
			break;
		}
		}
	}
}


int main()
{
	setlocale(0, "");

	do
	{
		printInterface();
		checkProgramContinue();
	} while (!_isProgramStop);

	return 0;
}