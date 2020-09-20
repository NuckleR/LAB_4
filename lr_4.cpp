#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <Windows.h>
#include <ctime>

int counter_1;
double counter_2, counter_3, temp;

enum workplace {
	without_man, with_man
};

class Casino {
//private:
private:
	std::string name;
protected:
	double money;
	int players;
	int workers;
public:
	Casino() {
		std::cout << "Заработал конструктор по умолчанию (Casino)!\n";
		money = 0;
		players = 0;
		workers = 0;
		name = "Пусто";
	}
	Casino(double mon, int play, 
		int work, std::string h) {
		std::cout << "Заработал конструктор инициализации (Casino)!\n";
		money = mon;
		players = play;
		workers = work;
		name = h;
	}
	Casino(Casino& one) : money(one.money),
		players(one.players), workers(one.workers), 
		name(one.name){
		std::cout << "Заработал конструктор копирования (Casino)!\n";
	}
	~Casino() {
		std::cout << "Заработал деструктор (Casino)!\n";
	}
	void set_players(int amnt) {
		players = amnt;
	}
	int get_players() {
		return players;
	}
	void set_workers(int amnt) {
		workers = amnt;
	}
	int get_workers() {
		return workers;
	}
	void set_money(double amnt) {
		money = amnt;
	}
	double get_money() {
		return money;
	}
	std::string get_name() {
		return name;
	}
	void enter_name() {
		rewind(stdin);
		rewind(stdout);
		std::string nm;
		std::cout << "Введите название казино: ";
		std::getline(std::cin, nm);
		name = nm;
	}
	void set_name(std::string nm) {
		name = nm;
	}

	void Casino_info() {
		std::cout << "Название казино: " << name << "\n\nКол-во посетителей: " << players
			<< "\nКол-во рабочих: " << workers << "\nДенег в кассе: " << money
			<<"\n\n";
	}
};




class Cards : public Casino {
protected:
	/*int* tables;*/
	int amnt_of_tables;
	double play_payment;
public:
	Cards() {
		std::cout << "Заработал конструктор по умолчанию (Cards)!\n";
		play_payment = 0;
		amnt_of_tables = 0;
		/*tables = nullptr;*/
	}
	Cards(double pay, int amnt) {
		std::cout << "Заработал конструктор инициализации (Cards)!\n";
		play_payment = pay;
		amnt_of_tables = amnt;
		/*tables = new int[amnt];*/
	}
	Cards(Cards& one) : amnt_of_tables(one.amnt_of_tables),
		/*tables(one.tables),*/ play_payment(one.play_payment){
		std::cout << "Заработал конструктор копирования (Cards)!\n";
	}
	~Cards() {
		std::cout << "Заработал деструктор (Card)!\n";
		/*delete tables;*/
	}
	void set_play_payment(double set) {
		play_payment = set;
	}
	double get_play_payment() {
		return play_payment;
	}
	void set_amnt_of_tables(int set) {
		amnt_of_tables = set;
	/*	tables = new int[set];*/
	}
	int get_amnt_of_tables() {
		return amnt_of_tables;
	}
	void Cards_info(Casino& C) {
		std::cout << "\n\n\tНазвание казино: " << C.get_name() << "\n\nКол-во игроков: " << players
			<< "\nКол-во рабочих: " << workers << "\nДенег в кассе: " << money
			<< "\nКол-во столов с карточнми играми: " << amnt_of_tables
			<< "\nПлата за возможность присоединится: " << play_payment << "\n\n";
	}
};


class Poker : public Cards{
protected:
	double win_rate;
	int table_id;
private:
	int workplace;
public:
	Poker() {
		std::cout << "Заработал конструктор по умолчанию (Cards)!\n";
		table_id = 0;
	}
	Poker(int Id) {
		std::cout << "Заработал конструктор инициализации (Cards)!\n";
		table_id = Id;
	}
	Poker(Poker& one) : table_id(one.table_id) {
		std::cout << "Заработал конструктор копирования (Cards)!\n";
	}
	~Poker() {
		std::cout << "Заработал деструктор (Card)!\n";
	}
	void set_win_rate(double set) {
		win_rate = set;
	}
	void set_table_id(double set) {
		table_id= set;
	}
	double get_table_id() {
		return table_id;
	}
	double get_win_rate() {
		return win_rate;
	}
	void set_workplace() {
		if (workers != without_man) workplace = with_man;
		else workplace = without_man;
	}
	int get_workplace() {
		return workplace;
	}
	void only_work(Casino& C) {
		if (workplace == with_man) {
			std::cout << "\n\n\tНазвание казино: " << C.get_name() << "\n\nНомер стола: " << table_id
				<< "\nКол-во игроков на картах: " << players
				<< "\nКол-во рабочих на картах: " << workers << "\nВсего денег в кассе на картах: " << money 
				<< "\nWIN_RATE: " << win_rate << "\n\n";
		}
	}
	void Poker_info(Casino& C) {
		std::cout << "\n\n\tНазвание казино: " << C.get_name() <<"\n\nНомер стола: " << table_id 
			<<"\nКол-во игроков на картах: " << players
			<< "\nКол-во рабочих на картах: " << workers << "\nВсего денег в кассе на картах: " << money
			<< "\nWIN_RATE: "<< win_rate <<"\n\n";
	}
};



class Slots : public Casino {
protected:
	//int* playgrounds;
	int amount_of_playgrounds;
	double chance_to_lose_money;
	double chance_to_win_money;
public:
	Slots() {
		std::cout << "Заработал конструктор по умолчанию (Slots)!\n";
		chance_to_lose_money = 0;
		chance_to_win_money = 0;
		amount_of_playgrounds = 0;
		//playgrounds = nullptr;
	}
	Slots(double ch_1, double ch_2, int set) {
		std::cout << "Заработал конструктор инициализации (Slots)!\n";
		chance_to_lose_money = ch_1;
		chance_to_win_money = ch_2;
		amount_of_playgrounds = set;
		//playgrounds = new int[set];
	}
	//Slots(Slots& one): chance_to_lose_money(one.get_chance_to_lose_money),
	//	chance_to_win_money(one.chance_to_win_money), 
	//	amount_of_playgrounds(one.amount_of_playgrounds){
	//	std::cout << "Заработал конструктор копирования (Slots)!\n";
	//}
	~Slots() {
		std::cout << "Заработал деструктор (Slots)!\n";
	}
	void set_chances() {
			chance_to_lose_money = (players * workers)*0.3*23;
			chance_to_win_money = (double)100 - chance_to_lose_money;
	}
	void set_chance_to_lose_money(double ch) {
		chance_to_lose_money = ch;
	}
	void set_chance_to_win_money(double ch) {
		chance_to_win_money = ch;
	}
	double get_chance_to_lose_money() {
		return chance_to_lose_money;
	}
	double get_chance_to_win_money() {
		return chance_to_win_money;
	}
	void set_amnt_of_pg(int set) {
		amount_of_playgrounds = set;
	}
	int get_amnt_of_pg() {
		return amount_of_playgrounds;
	}
	void Slots_info(Casino &C) {
		std::cout << "\n\n\tНазвание казино: " << C.get_name() << "\n\nКол-во игроков на слотах: " << players
			<< "\nКол-во рабочих на слотах: " << workers << "\nВсего денег в кассе на слотах: " << money
			<< "\nКол-во колес фортуны: " << amount_of_playgrounds
			<< "\nШанс прибыли: " << chance_to_win_money << "%" 
			<< "\t\tШанс убыли: " << chance_to_lose_money << "%" << "\n\n";
	}
};



class Wheel_of_Luck : public Slots {
protected:
	int playground_id;
	double rotation_speed;
private:
	int workplace;
public:
	Wheel_of_Luck() {
		std::cout << "Заработал конструктор по умолчанию (Slots)!\n";
		chance_to_lose_money = 0;
		chance_to_win_money = 0;
		rotation_speed = 1;
		playground_id = -1;
	}
	Wheel_of_Luck(double ch_1, double ch_2, double r_s, int ID) {
		std::cout << "Заработал конструктор инициализации (Slots)!\n";
		chance_to_lose_money = ch_1;
		chance_to_win_money = ch_2;
		rotation_speed = r_s;
		playground_id = ID;
	}
	Wheel_of_Luck(Wheel_of_Luck& one) : playground_id(one.playground_id),
		rotation_speed(one.rotation_speed){
		std::cout << "Заработал конструктор копирования (Slots)!\n";
	}
	~Wheel_of_Luck() {
		std::cout << "Заработал деструктор (Slots)!\n";
	}
	void set_rotation_speed(double speed) {
		rotation_speed = speed;
	}
	double get_rotation_speed() {
		return rotation_speed;
	}
	void only_work(Casino& C) {
		if (workplace == with_man) {
			double temp = chance_to_lose_money * rotation_speed;

			std::cout << "\n\n\tНазвание казино: " << C.get_name()
				<< "\n\nНомер колеса: " << playground_id
				<< "\nКол-во посетителей: " << players
				<< "\nКол-во рабочих: " << workers
				<< "\nДенег в кассе: " << money
				<< "\nШанс прибыли: " << chance_to_win_money << "%"
				<< "\t\tШанс убыли: " << temp << "%"
				<< "\nСкорость вращения: " << rotation_speed << "\n\n";
		}
	}
	void Wheel_of_Luck_info(Casino& C) {
		double temp = chance_to_lose_money * rotation_speed;

		std::cout << "\n\n\tНазвание казино: " << C.get_name() 
			<< "\n\nНомер колеса: " << playground_id
			<< "\nКол-во посетителей: " << players
			<< "\nКол-во рабочих: " << workers
			<< "\nДенег в кассе: " << money
			<< "\nШанс прибыли: " << chance_to_win_money << "%" 
			<< "\t\tШанс убыли: " << temp << "%"
			<< "\nСкорость вращения: " << rotation_speed <<"\n\n";
	}
	void set_playground_id(double set) {
		playground_id = set;
	}
	double get_playground_id() {
		return playground_id;
	}
	void set_workplace() {
		if (workers != without_man) workplace = with_man;
		else workplace = without_man;
	}
	int get_workplace() {
		return workplace;
	}
};


class Well_Buissnes: public Poker, public Wheel_of_Luck {
public:
	double analitics;
	int exp_amnt_of_players;
	double common_win_rate;
	double efficiency_of_workers;
	double profit;
	double money;

	Well_Buissnes() {
		analitics = 0;
		exp_amnt_of_players = 0;
		common_win_rate = 0;
	};
	~Well_Buissnes() {};
	void set_m(double m) {
		money = m;
	}
	void set_analitics(double set) {
		analitics = set;
	}
	void set_exp_amnt_of_players(int set) {
		exp_amnt_of_players = set;
	}
	void set_common_win_rate(double set) {
		common_win_rate = set;
	}
	void set_ef_of_work(double set) {
		efficiency_of_workers = set;
	}
	void set_profit(double set) {
		profit = set;
	}
	void Well_Bussines_info(Casino& C) {
		std::cout << "\n\n\tНазвание казино: " << C.get_name()
			<< "\n\nОжидаемое кол-во людей: " << exp_amnt_of_players
			<< "\nЭффективность найма рабочих: " << efficiency_of_workers << "%"
			<< "\nОбщий рейтинг побед (как в колесе фартуны, так и в покере): " << common_win_rate<<"%"
			<< "\nЗароботок за сыгровку всех карточных столов: " << profit
			<< "\nДеньги: "<< money
			<<"\nОценка бизнеса: \n" << analitics
			<< "\n\n";
	}
};

double count(Well_Buissnes& Class);
void enter_amnt(int& amnt_of, std::string name);

void clear_count();

int main() {
	system("chcp 1251");
	system("CLS");
	srand(time(0));

	Casino Royal;
	Cards games;
	Poker *poker;
	Slots slots;
	Wheel_of_Luck *wheel_of_luck;
	Well_Buissnes analitics;

	std::string str;
	int workers, players, money, amnt_of;

	while (true) {
		system("CLS");
		Royal.enter_name();

		enter_amnt(amnt_of, "Колеса фартуны: ");
		slots.set_amnt_of_pg(amnt_of);
		enter_amnt(amnt_of, "Столы для покера: ");
		games.set_amnt_of_tables(amnt_of);

		std::cout << "\n\n\t\t\tЗАПОЛНЕНИЕ ПОКЕРНЫХ СТОЛОВ!\n\n\n";
		wheel_of_luck = new Wheel_of_Luck[slots.get_amnt_of_pg()];
		poker = new Poker[games.get_amnt_of_tables()];
		for (counter_1 = 0; counter_1 < games.get_amnt_of_tables(); counter_1++) {
			poker[counter_1].set_table_id(counter_1 + 1);
			poker[counter_1].set_money(rand() % 5000 + 1000);
			poker[counter_1].set_workers((rand() % 2));
			if (poker[counter_1].get_workers() != 0) {
				poker[counter_1].set_players((1 + rand() % 6));
			}
			poker[counter_1].set_play_payment((40 + rand() % 360));
			poker[counter_1].set_workplace();
			poker[counter_1].set_win_rate(rand() % 100);
			poker[counter_1].Poker_info(Royal);
		} clear_count();

		system("pause");

		std::cout << "\n\n\t\t\tЗАПОЛНЕНИЕ КОЛЕС ФАРТУНЫ!\n\n\n";
		for (counter_1 = 0; counter_1 < slots.get_amnt_of_pg(); counter_1++) {
			wheel_of_luck[counter_1].set_playground_id(counter_1 + 1);
			wheel_of_luck[counter_1].set_money(rand() % 5000 + 1000);
			wheel_of_luck[counter_1].set_workers(rand() % 2);
			if (wheel_of_luck[counter_1].get_workers() != 0) {
				wheel_of_luck[counter_1].set_players((rand() % 4 + 1));
			}
			wheel_of_luck[counter_1].set_amnt_of_pg(slots.get_amnt_of_pg());
			wheel_of_luck[counter_1].set_chances();
			wheel_of_luck[counter_1].set_rotation_speed(((double)(10 + (rand() % 10))) / 10);
			wheel_of_luck[counter_1].set_workplace();
			wheel_of_luck[counter_1].Wheel_of_Luck_info(Royal);
		} clear_count();

		system("pause");

		std::cout << "\n\n\t\t\tЗАПОЛНЕНИЕ КАРТОЧНЫХ ИГР!\n\n\n";
		for (counter_1 = 0; counter_1 < games.get_amnt_of_tables(); counter_1++) {
			temp += poker[counter_1].get_players();
		}games.set_players(temp); clear_count();
		for (counter_1 = 0; counter_1 < games.get_amnt_of_tables(); counter_1++) {
			temp += poker[counter_1].get_money();
		}games.set_money(temp); clear_count();
		for (counter_1 = 0; counter_1 < games.get_amnt_of_tables(); counter_1++) {
			temp += poker[counter_1].get_workers();
		}games.set_workers(temp); clear_count();
		for (counter_1 = 0; counter_1 < games.get_amnt_of_tables(); counter_1++) {
			temp += poker[counter_1].get_play_payment();
		}games.set_play_payment(temp / games.get_amnt_of_tables()); clear_count();
		games.Cards_info(Royal);

		system("pause");

		std::cout << "\n\n\t\t\tЗАПОЛНЕНИЕ СЛОТОВЫХ ИГР!\n\n\n";
		for (counter_1 = 0; counter_1 < slots.get_amnt_of_pg(); counter_1++) {
			temp += wheel_of_luck[counter_1].get_players();
		} slots.set_players(temp); clear_count();
		for (counter_1 = 0; counter_1 < slots.get_amnt_of_pg(); counter_1++) {
			temp += wheel_of_luck[counter_1].get_workers();
		} slots.set_workers(temp); clear_count();
		for (counter_1 = 0; counter_1 < slots.get_amnt_of_pg(); counter_1++) {
			temp += wheel_of_luck[counter_1].get_money();
		}slots.set_money(temp); clear_count();
		for (counter_1 = 0; counter_1 < slots.get_amnt_of_pg(); counter_1++) {
			temp += wheel_of_luck[counter_1].get_chance_to_lose_money();
		} slots.set_chance_to_lose_money(temp / slots.get_amnt_of_pg()); clear_count();
		for (counter_1 = 0; counter_1 < slots.get_amnt_of_pg(); counter_1++) {
			temp += wheel_of_luck[counter_1].get_chance_to_win_money();
		} slots.set_chance_to_win_money(temp / slots.get_amnt_of_pg()); clear_count();
		slots.Slots_info(Royal);

		system("pause");

		std::cout << "\n\n\t\t\tОСНОВНАЯ ИНФОРМАЦИЯ О КАЗИНО!\n\n\n";
		Royal.set_money(slots.get_money() + games.get_money());
		Royal.set_players(slots.get_players() + games.get_players());
		Royal.set_workers(slots.get_workers() + games.get_workers());
		Royal.Casino_info();

		system("pause");

		std::cout << "\n\n\t\t\tАНАЛИЗ БИЗНЕСА КАЗИНО!\n\n\n";
		analitics.set_exp_amnt_of_players((slots.get_amnt_of_pg() * 3 + games.get_amnt_of_tables() * 6));
		for (counter_1 = 0; counter_1 < slots.get_amnt_of_pg(); counter_1++) {
			if (wheel_of_luck[counter_1].get_workplace() != without_man) {
				temp += wheel_of_luck[counter_1].get_chance_to_lose_money();
				counter_3++;
			}
		}
		for (counter_1 = 0; counter_1 < games.get_amnt_of_tables(); counter_1++) {
			if (poker[counter_1].get_workplace() != without_man) {
				counter_2 += poker[counter_1].get_win_rate();
				counter_3++;
			}
		}
		analitics.set_common_win_rate((double)(temp + counter_2) / (double)counter_3);
		analitics.set_ef_of_work(((double)Royal.get_players() / (double)Royal.get_workers()) * 25);
		clear_count();
		for (counter_1 = 0; counter_1 < games.get_amnt_of_tables(); counter_1++) {
			temp += poker[counter_1].get_play_payment();
		} analitics.set_profit(temp); clear_count();
		analitics.set_m(Royal.get_money());
		analitics.set_analitics(count(analitics));
		analitics.Well_Bussines_info(Royal);

		std::cout << "\n\n\t\tПОВТОР!?\n\n 1 - ДА \t\t 0 - НЕТ\n\n ";
		do {
			std::cin >> temp;
			if (temp < 0 || temp>1) {
				std::cout << "\nПредел!"
					<< "\nПопробуйте ещё раз!";
			}
		} while (temp < 0 || temp>1);
		if (temp == 1) continue;
		else break;
	}

	delete poker;
	delete wheel_of_luck;
	return 0;
}

void clear_count() {
	counter_1 = 0;
	counter_2 = 0;
	counter_3 = 0;
	temp = 0;
}

void enter_amnt(int& amnt_of, std::string name) {
	do {
		std::cout << "\n\nВведите кол-во " << name << ": ";
		std::cin >> amnt_of;
		if (amnt_of < 0 || amnt_of>50) {
			std::cout << "\nПредел " << name << "!"
				<< "\nПопробуйте ещё раз!";		
		}
	} while (amnt_of < 0 || amnt_of>50);
}

double count(Well_Buissnes &Class) {
	double temp_1 = 0;
	
	temp_1 += Class.common_win_rate / 10;
	temp_1 += Class.efficiency_of_workers / 10;
	//if (Class.money <= 100000) {
	temp_1 += ((Class.money / 10000) + (Class.efficiency_of_workers / 10)) / 2;
	//}
	//else {
	//	temp_1 += (10 + (Class.efficiency_of_workers / 10)) / 2;
	//}
	temp_1 = temp_1 / 3;
	if (temp_1 >= 10) {
		temp_1 = 10;
	}
	return temp_1;
}