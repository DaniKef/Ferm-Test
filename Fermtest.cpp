#include "iostream"
using namespace std;

int modexp(int x, int y, int N)
{
	if (y == 0) return 1;
	int z = modexp(x, y / 2, N);
	if (y % 2 == 0)
		return (z * z) % N;
	else
		return (x * z * z) % N;
}

bool ferm(int n) {
	bool a;
	for (int i = 2; i <= n - 2 && i < 3; i++) {
		if (modexp(i, n - 1, n) == 1)
			a = true;
		else
			return false;
	}
	return a;
}
int main()
{
	int n;
	cin >> n;
	if (ferm(n))
		cout << "The number is probably prime" << endl;
	else
		cout << "The number is compound" << endl;
	system("pause");
	return 0;
}

