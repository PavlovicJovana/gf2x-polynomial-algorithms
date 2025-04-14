#include <NTL/GF2X.h>
#include <bits/stdc++.h>

using namespace std;

NTL::GF2X first_level_blocking(long r, long s) {
	NTL::GF2X G, T, X, P, P_pom;

	SetCoeff(T, r, 1);
	SetCoeff(T, s, 1);
	SetCoeff(T, 0, 1);

	SetX(X);

	P = SqrMod(X, T);
	SetCoeff(P, 1, 1);

	for(int i = 1; i <= r/2 - 1; i++) {
		X = SqrMod(X, T);

		P_pom = X;
		SetCoeff(P_pom, 1, 1);
		P = MulMod(P, P_pom, T);
	}

	GCD(G, T, P);
	return G;
}

int main() {
	clock_t start, end;
	start = clock();

	std::cout << "First level blocking: " << first_level_blocking(1279, 216) << std::endl;

	end = clock();
	double time_taken = double(end-start) / double(CLOCKS_PER_SEC);

	std::cout << "Time: " << fixed << time_taken << std::setprecision(5) << " sec" << std::endl;

	return 0;
}