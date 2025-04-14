#include <NTL/GF2X.h>
#include <bits/stdc++.h>

using namespace std;

int hamming_weight(int k) {
	int weight = 0;
	while (k>0) {
		weight += k & 1;
		k >>= 1;
	}

	return weight;
}

NTL::GF2X calculate_S_j_m(long j, long m, const NTL::GF2X& X_d, const NTL::GF2X& T) {
	NTL::GF2X new_S_j_m = NTL::GF2X();

	for (int k = 0; k < pow(2, m); k++) {
		if (hamming_weight(k) == j)
			new_S_j_m += PowerMod(X_d, k, T);
	}

	return new_S_j_m;
}

NTL::GF2X second_level_blocking(long r, long s) {
	NTL::GF2X G, T, X, P, sum;
	NTL::GF2X S_j_m[m+1];

	SetCoeff(T, r, 1);
	SetCoeff(T, s, 1);
	SetCoeff(T, 0, 1);

	SetX(X);
	SetCoeff(P, 0, 1);

	for(int i = 0; i < (r/2)/m; i++) {
		sum = 0;

		for (int j = 0; j <= m; j++) {
			if (i == 0) {
				if (j == 0)
					S_j_m[j] = 1;
				else
					S_j_m[j] = calculate_S_j_m(j, m, SqrMod(X, T), T);
			} else 
				S_j_m[j] = PowerMod(S_j_m[j], pow(2, m), T);
			
			sum += MulMod(PowerMod(X, m-j, T), S_j_m[j], T);
		}

		P = MulMod(P, sum, T);
	}

	GCD(G, T, P);
	return G;
}

int main() {
	clock_t start, end;
	start = clock();

	std::cout << "Second level blocking: " << second_level_blocking(1279, 216, 5) << std::endl;

	end = clock();
	double time_taken = double(end-start) / double(CLOCKS_PER_SEC);

	std::cout << "Time: " << fixed << time_taken << std::setprecision(5) << " sec" << std::endl;

	return 0;
}