/*
	THUC HANH TUAN 10 - 18.04.2023
	CODE BY HUYNH KHUAN
*/

#include <iostream>
#include <climits>

/*
	HAM NHAP MANG
*/

void EnterArray(int arr[], int& n) {
	std::cout << "Nhap so phan tu trong mang : "; std::cin >> n;
	std::cout << "\t- NHAP MANG -\n";
	for (int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] : ";
		std::cin >> arr[i];
	}
}

/*
	HAM TIM SO AM LON NHAT
*/

void FindLocationNegativeElements(int arr[], int n) {
	int largestNegativeValue = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (arr[i] < 0 && arr[i] > largestNegativeValue) {
			largestNegativeValue = arr[i];
		}
	}

	if (largestNegativeValue == INT_MIN) {
		std::cout << "\n2.\t=> Khong co phan tu am nao trong mang! <=\n"; 
		return;
	}

	std::cout << "\n3.\t=> Gia tri am lon nhat trong mang la : " << largestNegativeValue << " <=" << std::endl;
	std::cout << "\t=> Chi so cua cac phan tu am lon nhat la : ";
	for (int i = 0; i < n; i++) {
		if (arr[i] == largestNegativeValue) {
			std::cout << i << " ";
		}
	}
	std::cout << "<=";
	std::cout << std::endl;

	std::cout << "\t=> Vi tri cua cac phan tu am lon nhat la : ";
	for (int i = 0; i < n; i++) {
		if (arr[i] == largestNegativeValue) {
			std::cout << i + 1 << " ";
		}
	}
	std::cout << "<=";
	std::cout << std::endl;
}

/*
	HAM TIM SO DUONG NHO NHAT
*/

void FindPositionOfPositiveElement(int arr[], int n) {
	int SmallestPositiveValue = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (arr[i] > 0 && arr[i] < SmallestPositiveValue) {
			SmallestPositiveValue = arr[i];
		}
	}

	if (SmallestPositiveValue == INT_MAX) {
		std::cout << "\n3.\t=> Khong co phan tu duong nao trong mang! <=\n";
		return;
	}

	std::cout << "\n3.\t=> Gia tri duong nho nhat trong mang la : " << SmallestPositiveValue << " <=" << std::endl;
	std::cout << "\t=> Chi so cua cac phan tu duong nho nhat la : ";
	for (int i = 0; i < n; i++) {
		if (arr[i] == SmallestPositiveValue) {
			std::cout << i << " ";
		}
	}
	std::cout << "<=";
	std::cout << std::endl;

	std::cout << "\t=> Vi tri cua cac phan tu duong nho nhat la : ";
	for (int i = 0; i < n; i++) {
		if (arr[i] == SmallestPositiveValue) {
			std::cout << i + 1 << " ";
		}
	}
	std::cout << "<=";
	std::cout << std::endl;
}

/*
	HAM GIA TRI XUAT HIEN NHIEU NHAT TRONG MANG
	GIAI PHAP 1
*/

int FindMostFrequent(int arr[], int n) {
	int max_value = arr[0];
	int min_value = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
		if (arr[i] < min_value) {
			min_value = arr[i];
		}
	}

	int range = max_value - min_value + 1;
	int* count = new int[range]();
	for (int i = 0; i < n; i++) {
		count[arr[i] - min_value]++;
	}

	int max_count = count[0];
	int max_index = 0;
	for (int i = 1; i < range; i++) {
		if (count[i] > max_count) {
			max_count = count[i];
			max_index = i;
		}
	}

	delete[] count;
	return max_index + min_value;
}

/*
	HAM GIA TRI XUAT HIEN NHIEU NHAT TRONG MANG
	GIAI PHAP 2
*/

void FindMostFrequent_Solution2(int arr[], int arrB[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (arr[j] == arr[i]) {
				arrB[i]++;
			}
		}
	}
}

/*
	HAM GIA TRI XUAT HIEN NHIEU NHAT TRONG MANG
	GIAI PHAP 2 - XUAT GIA TRI
*/

void Export_FindMostFrequent_Solution2(int arr[], int arrB[], int n) {
	int max = 1;
	for (int i = 0; i < n; i++) {
		if (arrB[i] > max) {
			max = arrB[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (arrB[i] == max) {
			std::cout << "\n4.\t=> Phan tu co gia tri : " << arr[i] << " xuat hien " << arrB[i] << " lan. <=\n";
		}
	}
}

/*
	HAM TIM CAP I + J = X
*/

int FindPairOfElements(int arr[], int n, int x) {
	int count = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == x) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	// Khai bao hang MAXSIZE = 100;
	const int MAXSIZE = 100;
	
	// Khai bao mang A
	int arr[MAXSIZE] = { 0 };

	// Khai bao mang A
	int arrB[MAXSIZE] = { 0 };

	// Khai bao n
	int n;

	// Nhap mang, duyet mang va xuat phan tu trong mang
	EnterArray(arr, n);
	std::cout << "\n1.\t=> Mang ban vua nhap la : ";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "<=";
	std::cout << std::endl;

	// Tim gia tri am lon nhat trong mang
	FindLocationNegativeElements(arr, n);

	// Tim gia tri duong nho nhat trong mang
	FindPositionOfPositiveElement(arr, n);

	// Giai phap 1 : tim phan tu xuat hien nhieu nhat trong mang
	//std::cout << "Phan tu xuat hien nhieu nhat trong mang : " << FindMostFrequent(arr, n) << std::endl;
	
	// Giai phap 2 : tim phan tu xuat hien nhieu nhat trong mang
	FindMostFrequent_Solution2(arr, arrB, n);

	// Xuat giai phap 2
	Export_FindMostFrequent_Solution2(arr, arrB, n);

	// Nhap x va tinh tong i + j = X va tinh tong co bao nhieu cap i + j = X
	int x;  std::cout << "\n5.\tNhap gia tri X : "; std::cin >> x;
	std::cout << "\t=> So luong cap (i, j) thoa man a[i] + a[j] = X la: " << FindPairOfElements(arr, n, x) << " <=" << std::endl;

	return 0;

	/*
		End
	*/
}