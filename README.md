# GF(2) Polynomial Algorithms - Master Thesis

This repository contains C++ implementations of three efficient algorithms for finding irreducible trinomials over the finite field GF(2), based on techniques discussed in my MSc thesis: 
**"The great trinomial hunt"**.

## Problem Overview

We search for irreducible trinomials of the form `x^r + x^s + 1`, where r > s > 0, over GF(2). These trinomials are significant in cryptography and pseudorandom number generation, particularly in constructing 
finite fields GF(2^r). The goal is to optimize the search for such trinomials using three algorithmic approaches.

## Implemented Algorithms

### 1. Basic Sieving
Performs GCD checks between the trinomial and polynomials of the form `x^{2^d} - x` for small `d`.
- Complexity: O(r/2 · (M(r)·log(r) + r)), where M(r) is the cost of multiplying two polynomials of degree less than `r` over GF(2).

### 2. First-Level Blocking
Replaces `r/2` GCD computations with a single GCD and `(r/2 - 1)` modular multiplications.
- Complexity: O(M(r)·log(r) + r/2 · (M(r) + r))

### 3. Second-Level Blocking
Further improves performance by reducing modular multiplications using a precomputed structure based on Hamming weights.
- Complexity: O(M(r)·log(r) + (r^2)/2 · m), for well-chosen `m`.

## Requirements

- [NTL (Number Theory Library)](https://libntl.org/)
- C++11 or later

