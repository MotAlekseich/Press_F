#include <iostream>
#include <cstdlib>
#include <ctime>
template <typename T>
void fill_arr(T arr[], int length, int l, int r) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (r - l) + l;
}
template <typename T>
void print_arr(T arr[], int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}


int max_num(int a, int b){
//1
	while (a > 0 && b > 0) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	if (a > b)
		return a;

	else
		return b;
}
//2
int mirror_number(int number) {
	int result{};
	int temp = number;
	while (temp > 0) {
		result = result * 10 + (temp % 10); 
		temp /= 10;
	}

	return result;
}
//3
int return_N(int arr[], int length, int n) {
	int num{};
	for (int i = 0; i < length - 1; i++)
		if (arr[i] == n) {
			num = i;
			break;
		}
	int tmp;
	if (num == 0) {
		std::cout << "ERROR";
		return -1;
	}
	else
		for (int i = length - 1; i > 0; i--) {
			for (int j = num + 1; j < i; j++)
				if (arr[j] > arr[j + 1]) {
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
		
	}


		return num;
}

void build_arr(int arr[], int length, int a, int b) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (b - a + 1) + a;
}


int main() {
	setlocale(LC_ALL, "Russian");
	//1
	std::cout << "Задача 1\n" << max_num(120, 100) << std::endl;
	std::cout << '\n';
	//2
	std::cout << "Задача 2\n";
	std::cout << mirror_number(23231);
	std::cout << '\n';

	//3
	std::cout << "\nЗадача 3\n";
	const int size = 20;
	int n{};
	int arr1[size];
	fill_arr(arr1, size, 1, 100);
	std::cout << "Первоначальный массив: \n";
	print_arr(arr1, size);
	std::cout << "Введите число -> " << std::endl;
	std::cin >> n;
	std::cout << "индекс искомого числа и итоговый массив: \n";
	std::cout << '<' << return_N(arr1, size, n) << '>';
	print_arr(arr1, size);
	std::cout << '\n';
	//4
	std::cout << "Задача 4\n";
	const int size2 = 10;
	int a, b;
	std::cout << "Задайте начало диапазона ->\n";
	std::cin >> a;
	std::cout << "Задайте конец диапазона ->\n";
	std::cin >> b;
	int arr2[size2];
	build_arr(arr2, size2, a, b);
	std::cout << "Сгенерированный массив:\n";
	print_arr(arr2, size2);

	return 0;

}