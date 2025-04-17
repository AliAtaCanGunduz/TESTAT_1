#include <iostream>
#include <chrono>
int fibonacci(int deger) {
	if (deger== 0) {
		return 0;
	}
	if (deger== 1 ||deger==2) {
		return 1;

	}
	else {
		return (fibonacci(deger- 1) + fibonacci(deger- 2));
		
		

	}
}
int main()
{
	int AG = 25;

	int A = fibonacci(AG);
	std::cout<<A<<std::endl;
	int n = 42;//42 rekursiv
	auto start = std::chrono::high_resolution_clock::now();
	int result = fibonacci(n);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

	std::cout << "\nBeispiel: f(" << n << ") = " << result
		<< " [" << duration.count() << " ns]" << std::endl;
	//1550348400 ns zeit also langsammer als iterativ



}
//75025 fibonnaci(25);

