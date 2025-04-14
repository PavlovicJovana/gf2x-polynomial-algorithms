#include <NTL/GF2X.h>
#include <bits/stdc++.h>

using namespace std;

NTL::GF2X sieving(long r, long s) {
	NTL::GF2X G, F, T, X;

	SetCoeff(T, r, 1);
	SetCoeff(T, s, 1);
	SetCoeff(T, 0, 1);

	SetX(X);

	for(int i = 1; i <= r/2; i++) {
		X = SqrMod(X, T);

		F = X;
		SetCoeff(F, 1, 1);

		GCD(G, T, F);
		if (G != 1) break;
	}

	return G;
}

int main() {
	clock_t start, end;
	start = clock();

	std::cout << "Sieving: " << sieving(1279, 216) << std::endl;

	end = clock();
	double time_taken = double(end-start) / double(CLOCKS_PER_SEC);

	std::cout << "Time: " << fixed << time_taken << std::setprecision(5) << " sec" << std::endl;

	return 0;
}