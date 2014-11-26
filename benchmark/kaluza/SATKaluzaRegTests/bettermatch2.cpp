/*
Author:   Joseph D. Scott
          Uppsala University

Used in:
          "Constraint Solving on Bounded String Variables"
          Scott, J.D., Flener, P. and Pearson, J.
          submitted to CPAIOR 2015
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

#include <gecode/driver.hh>
#include <gecode/minimodel.hh>

#include "open.hh"
#include "open-layered-graph.hh"

#define CSTRING(X,X_n,cstr) \
	str = cstr; \
	X = IntVarArray(*this, wordlength); \
	for (unsigned int i = 0; i < str.length(); i++) \
		X[i] = IntVar(*this, (int)str[i] - 31, (int)str[i] - 31); \
	for (int i=(int)str.length(); i<X.size(); i++) \
			X[i] = IntVar(*this, dummy_sym, dummy_sym); \
	X_n = IntVar(*this, str.length(), str.length());

#define PAD_INVARIANT(home, X, Xn) \
	for(int i=0; i<wordlength; i++) \
		rel(home,(X[i]==dummy_sym) == (Xn<=i));

#define PAD_EQUAL(home, X,Xn,Y,Yn) \
	rel(home, Xn == Yn); \
	for (int i = 0; i<wordlength;i++) \
		rel(home, (i<Xn) >> (X[i]==Y[i])); 
	
using namespace Gecode;
using namespace std;

int wordlength = 0;
int dummy_sym = Open::OpenString::padchar;
int val_dom_min = -1;
int val_dom_max = 96;

Gecode::DFA::Transition bigp[] = {
	{0,1,0},
	{0,2,0},
	{0,3,0},
	{0,4,0},
	{0,5,0},
	{0,6,0},
	{0,7,0},
	{0,8,0},
	{0,9,0},
	{0,10,0},
	{0,11,0},
	{0,12,0},
	{0,13,0},
	{0,14,0},
	{0,15,0},
	{0,16,0},
	{0,17,0},
	{0,18,0},
	{0,19,0},
	{0,20,0},
	{0,21,0},
	{0,22,0},
	{0,23,0},
	{0,24,0},
	{0,25,0},
	{0,26,0},
	{0,27,0},
	{0,28,0},
	{0,29,0},
	{0,30,0},
	{0,31,0},
	{0,32,0},
	{0,33,0},
	{0,34,0},
	{0,35,0},
	{0,36,0},
	{0,37,0},
	{0,38,0},
	{0,39,0},
	{0,40,0},
	{0,41,0},
	{0,42,0},
	{0,43,0},
	{0,44,0},
	{0,45,0},
	{0,46,0},
	{0,47,0},
	{0,48,0},
	{0,49,0},
	{0,50,0},
	{0,51,0},
	{0,52,0},
	{0,53,0},
	{0,54,0},
	{0,55,0},
	{0,56,0},
	{0,57,0},
	{0,58,0},
	{0,59,0},
	{0,60,0},
	{0,61,0},
	{0,62,0},
	{0,63,0},
	{0,64,0},
	{0,65,0},
	{0,66,0},
	{0,67,0},
	{0,68,0},
	{0,69,0},
	{0,70,0},
	{0,71,0},
	{0,72,0},
	{0,73,0},
	{0,74,0},
	{0,75,1},
	{0,76,0},
	{0,77,0},
	{0,78,0},
	{0,79,0},
	{0,80,0},
	{0,81,0},
	{0,82,0},
	{0,83,0},
	{0,84,0},
	{0,85,0},
	{0,86,0},
	{0,87,0},
	{0,88,0},
	{0,89,0},
	{0,90,0},
	{0,91,0},
	{0,92,0},
	{0,93,0},
	{0,94,0},
	{0,95,0},
	{0,96,0},
	{1,1,0},
	{1,2,0},
	{1,3,0},
	{1,4,0},
	{1,5,0},
	{1,6,0},
	{1,7,0},
	{1,8,0},
	{1,9,0},
	{1,10,0},
	{1,11,0},
	{1,12,0},
	{1,13,0},
	{1,14,0},
	{1,15,0},
	{1,16,0},
	{1,17,0},
	{1,18,0},
	{1,19,0},
	{1,20,0},
	{1,21,0},
	{1,22,0},
	{1,23,0},
	{1,24,0},
	{1,25,0},
	{1,26,0},
	{1,27,0},
	{1,28,0},
	{1,29,0},
	{1,30,0},
	{1,31,0},
	{1,32,0},
	{1,33,0},
	{1,34,0},
	{1,35,0},
	{1,36,0},
	{1,37,0},
	{1,38,0},
	{1,39,0},
	{1,40,0},
	{1,41,0},
	{1,42,0},
	{1,43,0},
	{1,44,0},
	{1,45,0},
	{1,46,0},
	{1,47,0},
	{1,48,0},
	{1,49,0},
	{1,50,0},
	{1,51,0},
	{1,52,0},
	{1,53,0},
	{1,54,0},
	{1,55,0},
	{1,56,0},
	{1,57,0},
	{1,58,0},
	{1,59,0},
	{1,60,0},
	{1,61,0},
	{1,62,0},
	{1,63,0},
	{1,64,0},
	{1,65,0},
	{1,66,0},
	{1,67,0},
	{1,68,0},
	{1,69,0},
	{1,70,0},
	{1,71,0},
	{1,72,0},
	{1,73,0},
	{1,74,0},
	{1,75,0},
	{1,76,0},
	{1,77,0},
	{1,78,0},
	{1,79,0},
	{1,80,2},
	{1,81,0},
	{1,82,0},
	{1,83,0},
	{1,84,0},
	{1,85,0},
	{1,86,0},
	{1,87,0},
	{1,88,0},
	{1,89,0},
	{1,90,0},
	{1,91,0},
	{1,92,0},
	{1,93,0},
	{1,94,0},
	{1,95,0},
	{1,96,0},
	{2,1,0},
	{2,2,0},
	{2,3,0},
	{2,4,0},
	{2,5,0},
	{2,6,0},
	{2,7,0},
	{2,8,0},
	{2,9,0},
	{2,10,0},
	{2,11,0},
	{2,12,0},
	{2,13,0},
	{2,14,0},
	{2,15,0},
	{2,16,0},
	{2,17,0},
	{2,18,0},
	{2,19,0},
	{2,20,0},
	{2,21,0},
	{2,22,0},
	{2,23,0},
	{2,24,0},
	{2,25,0},
	{2,26,0},
	{2,27,0},
	{2,28,0},
	{2,29,0},
	{2,30,0},
	{2,31,0},
	{2,32,0},
	{2,33,0},
	{2,34,0},
	{2,35,0},
	{2,36,0},
	{2,37,0},
	{2,38,0},
	{2,39,0},
	{2,40,0},
	{2,41,0},
	{2,42,0},
	{2,43,0},
	{2,44,0},
	{2,45,0},
	{2,46,0},
	{2,47,0},
	{2,48,0},
	{2,49,0},
	{2,50,0},
	{2,51,0},
	{2,52,0},
	{2,53,0},
	{2,54,0},
	{2,55,0},
	{2,56,0},
	{2,57,0},
	{2,58,0},
	{2,59,0},
	{2,60,0},
	{2,61,0},
	{2,62,0},
	{2,63,0},
	{2,64,0},
	{2,65,0},
	{2,66,0},
	{2,67,0},
	{2,68,0},
	{2,69,0},
	{2,70,0},
	{2,71,0},
	{2,72,0},
	{2,73,3},
	{2,74,0},
	{2,75,0},
	{2,76,0},
	{2,77,0},
	{2,78,0},
	{2,79,0},
	{2,80,0},
	{2,81,0},
	{2,82,0},
	{2,83,0},
	{2,84,0},
	{2,85,0},
	{2,86,0},
	{2,87,0},
	{2,88,0},
	{2,89,0},
	{2,90,0},
	{2,91,0},
	{2,92,0},
	{2,93,0},
	{2,94,0},
	{2,95,0},
	{2,96,0},
	{3,1,0},
	{3,2,0},
	{3,3,0},
	{3,4,0},
	{3,5,0},
	{3,6,0},
	{3,7,0},
	{3,8,0},
	{3,9,0},
	{3,10,0},
	{3,11,0},
	{3,12,0},
	{3,13,0},
	{3,14,0},
	{3,15,0},
	{3,16,0},
	{3,17,0},
	{3,18,0},
	{3,19,0},
	{3,20,0},
	{3,21,0},
	{3,22,0},
	{3,23,0},
	{3,24,0},
	{3,25,0},
	{3,26,0},
	{3,27,0},
	{3,28,0},
	{3,29,0},
	{3,30,0},
	{3,31,0},
	{3,32,0},
	{3,33,0},
	{3,34,0},
	{3,35,0},
	{3,36,0},
	{3,37,0},
	{3,38,0},
	{3,39,0},
	{3,40,0},
	{3,41,0},
	{3,42,0},
	{3,43,0},
	{3,44,0},
	{3,45,0},
	{3,46,0},
	{3,47,0},
	{3,48,0},
	{3,49,0},
	{3,50,0},
	{3,51,0},
	{3,52,0},
	{3,53,0},
	{3,54,0},
	{3,55,0},
	{3,56,0},
	{3,57,0},
	{3,58,0},
	{3,59,0},
	{3,60,0},
	{3,61,0},
	{3,62,0},
	{3,63,0},
	{3,64,0},
	{3,65,0},
	{3,66,0},
	{3,67,0},
	{3,68,0},
	{3,69,0},
	{3,70,0},
	{3,71,0},
	{3,72,0},
	{3,73,0},
	{3,74,0},
	{3,75,0},
	{3,76,0},
	{3,77,0},
	{3,78,0},
	{3,79,4},
	{3,80,0},
	{3,81,0},
	{3,82,0},
	{3,83,0},
	{3,84,0},
	{3,85,0},
	{3,86,0},
	{3,87,0},
	{3,88,0},
	{3,89,0},
	{3,90,0},
	{3,91,0},
	{3,92,0},
	{3,93,0},
	{3,94,0},
	{3,95,0},
	{3,96,0},
	{0,-1,5},
	{1,-1,5},
	{2,-1,5},
	{3,-1,5},
	{-1,0,0}
};

Gecode::DFA::Transition big[] = {
	{0,1,0},
	{0,2,0},
	{0,3,0},
	{0,4,0},
	{0,5,0},
	{0,6,0},
	{0,7,0},
	{0,8,0},
	{0,9,0},
	{0,10,0},
	{0,11,0},
	{0,12,0},
	{0,13,0},
	{0,14,0},
	{0,15,0},
	{0,16,0},
	{0,17,0},
	{0,18,0},
	{0,19,0},
	{0,20,0},
	{0,21,0},
	{0,22,0},
	{0,23,0},
	{0,24,0},
	{0,25,0},
	{0,26,0},
	{0,27,0},
	{0,28,0},
	{0,29,0},
	{0,30,0},
	{0,31,0},
	{0,32,0},
	{0,33,0},
	{0,34,0},
	{0,35,0},
	{0,36,0},
	{0,37,0},
	{0,38,0},
	{0,39,0},
	{0,40,0},
	{0,41,0},
	{0,42,0},
	{0,43,0},
	{0,44,0},
	{0,45,0},
	{0,46,0},
	{0,47,0},
	{0,48,0},
	{0,49,0},
	{0,50,0},
	{0,51,0},
	{0,52,0},
	{0,53,0},
	{0,54,0},
	{0,55,0},
	{0,56,0},
	{0,57,0},
	{0,58,0},
	{0,59,0},
	{0,60,0},
	{0,61,0},
	{0,62,0},
	{0,63,0},
	{0,64,0},
	{0,65,0},
	{0,66,0},
	{0,67,0},
	{0,68,0},
	{0,69,0},
	{0,70,0},
	{0,71,0},
	{0,72,0},
	{0,73,0},
	{0,74,0},
	{0,75,1},
	{0,76,0},
	{0,77,0},
	{0,78,0},
	{0,79,0},
	{0,80,0},
	{0,81,0},
	{0,82,0},
	{0,83,0},
	{0,84,0},
	{0,85,0},
	{0,86,0},
	{0,87,0},
	{0,88,0},
	{0,89,0},
	{0,90,0},
	{0,91,0},
	{0,92,0},
	{0,93,0},
	{0,94,0},
	{0,95,0},
	{0,96,0},
	{1,1,0},
	{1,2,0},
	{1,3,0},
	{1,4,0},
	{1,5,0},
	{1,6,0},
	{1,7,0},
	{1,8,0},
	{1,9,0},
	{1,10,0},
	{1,11,0},
	{1,12,0},
	{1,13,0},
	{1,14,0},
	{1,15,0},
	{1,16,0},
	{1,17,0},
	{1,18,0},
	{1,19,0},
	{1,20,0},
	{1,21,0},
	{1,22,0},
	{1,23,0},
	{1,24,0},
	{1,25,0},
	{1,26,0},
	{1,27,0},
	{1,28,0},
	{1,29,0},
	{1,30,0},
	{1,31,0},
	{1,32,0},
	{1,33,0},
	{1,34,0},
	{1,35,0},
	{1,36,0},
	{1,37,0},
	{1,38,0},
	{1,39,0},
	{1,40,0},
	{1,41,0},
	{1,42,0},
	{1,43,0},
	{1,44,0},
	{1,45,0},
	{1,46,0},
	{1,47,0},
	{1,48,0},
	{1,49,0},
	{1,50,0},
	{1,51,0},
	{1,52,0},
	{1,53,0},
	{1,54,0},
	{1,55,0},
	{1,56,0},
	{1,57,0},
	{1,58,0},
	{1,59,0},
	{1,60,0},
	{1,61,0},
	{1,62,0},
	{1,63,0},
	{1,64,0},
	{1,65,0},
	{1,66,0},
	{1,67,0},
	{1,68,0},
	{1,69,0},
	{1,70,0},
	{1,71,0},
	{1,72,0},
	{1,73,0},
	{1,74,0},
	{1,75,0},
	{1,76,0},
	{1,77,0},
	{1,78,0},
	{1,79,0},
	{1,80,2},
	{1,81,0},
	{1,82,0},
	{1,83,0},
	{1,84,0},
	{1,85,0},
	{1,86,0},
	{1,87,0},
	{1,88,0},
	{1,89,0},
	{1,90,0},
	{1,91,0},
	{1,92,0},
	{1,93,0},
	{1,94,0},
	{1,95,0},
	{1,96,0},
	{2,1,0},
	{2,2,0},
	{2,3,0},
	{2,4,0},
	{2,5,0},
	{2,6,0},
	{2,7,0},
	{2,8,0},
	{2,9,0},
	{2,10,0},
	{2,11,0},
	{2,12,0},
	{2,13,0},
	{2,14,0},
	{2,15,0},
	{2,16,0},
	{2,17,0},
	{2,18,0},
	{2,19,0},
	{2,20,0},
	{2,21,0},
	{2,22,0},
	{2,23,0},
	{2,24,0},
	{2,25,0},
	{2,26,0},
	{2,27,0},
	{2,28,0},
	{2,29,0},
	{2,30,0},
	{2,31,0},
	{2,32,0},
	{2,33,0},
	{2,34,0},
	{2,35,0},
	{2,36,0},
	{2,37,0},
	{2,38,0},
	{2,39,0},
	{2,40,0},
	{2,41,0},
	{2,42,0},
	{2,43,0},
	{2,44,0},
	{2,45,0},
	{2,46,0},
	{2,47,0},
	{2,48,0},
	{2,49,0},
	{2,50,0},
	{2,51,0},
	{2,52,0},
	{2,53,0},
	{2,54,0},
	{2,55,0},
	{2,56,0},
	{2,57,0},
	{2,58,0},
	{2,59,0},
	{2,60,0},
	{2,61,0},
	{2,62,0},
	{2,63,0},
	{2,64,0},
	{2,65,0},
	{2,66,0},
	{2,67,0},
	{2,68,0},
	{2,69,0},
	{2,70,0},
	{2,71,0},
	{2,72,0},
	{2,73,3},
	{2,74,0},
	{2,75,0},
	{2,76,0},
	{2,77,0},
	{2,78,0},
	{2,79,0},
	{2,80,0},
	{2,81,0},
	{2,82,0},
	{2,83,0},
	{2,84,0},
	{2,85,0},
	{2,86,0},
	{2,87,0},
	{2,88,0},
	{2,89,0},
	{2,90,0},
	{2,91,0},
	{2,92,0},
	{2,93,0},
	{2,94,0},
	{2,95,0},
	{2,96,0},
	{3,1,0},
	{3,2,0},
	{3,3,0},
	{3,4,0},
	{3,5,0},
	{3,6,0},
	{3,7,0},
	{3,8,0},
	{3,9,0},
	{3,10,0},
	{3,11,0},
	{3,12,0},
	{3,13,0},
	{3,14,0},
	{3,15,0},
	{3,16,0},
	{3,17,0},
	{3,18,0},
	{3,19,0},
	{3,20,0},
	{3,21,0},
	{3,22,0},
	{3,23,0},
	{3,24,0},
	{3,25,0},
	{3,26,0},
	{3,27,0},
	{3,28,0},
	{3,29,0},
	{3,30,0},
	{3,31,0},
	{3,32,0},
	{3,33,0},
	{3,34,0},
	{3,35,0},
	{3,36,0},
	{3,37,0},
	{3,38,0},
	{3,39,0},
	{3,40,0},
	{3,41,0},
	{3,42,0},
	{3,43,0},
	{3,44,0},
	{3,45,0},
	{3,46,0},
	{3,47,0},
	{3,48,0},
	{3,49,0},
	{3,50,0},
	{3,51,0},
	{3,52,0},
	{3,53,0},
	{3,54,0},
	{3,55,0},
	{3,56,0},
	{3,57,0},
	{3,58,0},
	{3,59,0},
	{3,60,0},
	{3,61,0},
	{3,62,0},
	{3,63,0},
	{3,64,0},
	{3,65,0},
	{3,66,0},
	{3,67,0},
	{3,68,0},
	{3,69,0},
	{3,70,0},
	{3,71,0},
	{3,72,0},
	{3,73,0},
	{3,74,0},
	{3,75,0},
	{3,76,0},
	{3,77,0},
	{3,78,0},
	{3,79,4},
	{3,80,0},
	{3,81,0},
	{3,82,0},
	{3,83,0},
	{3,84,0},
	{3,85,0},
	{3,86,0},
	{3,87,0},
	{3,88,0},
	{3,89,0},
	{3,90,0},
	{3,91,0},
	{3,92,0},
	{3,93,0},
	{3,94,0},
	{3,95,0},
	{3,96,0},
	{-1,0,0}
};

std::ostream&
select_ostream(const char* name, std::ofstream& ofs) {
  if (strcmp(name, "stdout") == 0) {
    return std::cout;
  } else if (strcmp(name, "stdlog") == 0) {
    return std::clog;
  } else if (strcmp(name, "stderr") == 0) {
    return std::cerr;
  } else {
    ofs.open(name);
    return ofs;
  }
}

class KaluzaExample : public Script {
	IntVar var_0xINPUT_9_n;
	IntVarArray var_0xINPUT_9;
	DFA notjohn;
public:
	enum {BRANCH_A_N, BRANCH_N_A, SEARCH_DFS, PROP_PAD, PROP_OPEN};
	KaluzaExample(const SizeOptions& opt)
		: var_0xINPUT_9_n(*this,1,wordlength),
			var_0xINPUT_9(*this,wordlength,val_dom_min,val_dom_max){
		switch(opt.propagation()){
			case PROP_PAD:
			{
				PAD_INVARIANT(*this,var_0xINPUT_9, var_0xINPUT_9_n);			
								// var_0xINPUT_9 \notin CapturedBrack(/john/, 0);
				int fp2[] = {0,1,2,3,5,-1};
				notjohn = DFA(0,bigp,fp2);
				extensional(*this, var_0xINPUT_9, notjohn);
				break;
			}
			case PROP_OPEN:
			{
				open_invariant(*this,var_0xINPUT_9, var_0xINPUT_9_n);
				// var_0xINPUT_9 \notin CapturedBrack(/john/, 0);
				int fp2[] = {0,1,2,3,5,-1};
				notjohn = DFA(0,bigp,fp2);
				extensional(*this, var_0xINPUT_9, notjohn);
// 				// var_0xINPUT_9 \notin CapturedBrack(/john/, 0);
// 				int f2[] = {0,1,2,3,5,-1};
// 				notjohn = DFA(0,big,f2);
// 				extensional(*this, var_0xINPUT_9, notjohn, var_0xINPUT_9_n);
				break;
			}
		}
		branch(*this, var_0xINPUT_9, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
	}
	
	KaluzaExample(bool share, KaluzaExample& s)
	: Script(share,s) {
			var_0xINPUT_9_n.update(*this, share, s.var_0xINPUT_9_n);
			var_0xINPUT_9.update(*this, share, s.var_0xINPUT_9);
			notjohn.update(*this, share, s.notjohn);
	}

	virtual Space* copy(bool share) {
		return new KaluzaExample(share,*this);
	}

	virtual void print(std::ostream& os) const {
		os << "bound = " << wordlength << endl; 
		os << "var_0xINPUT_9 = ";
		Open::OpenString::print(os,var_0xINPUT_9,var_0xINPUT_9_n);
		os << std::endl;
		Open::OpenString::printAsString(os,var_0xINPUT_9,var_0xINPUT_9_n);
	}
};

int main(int argc, char* argv[]) {
	SizeOptions opt("Kaluza Example");
	opt.solutions(1); // only need one solution
  opt.size(30);
  opt.propagation(KaluzaExample::PROP_OPEN,   "open",    "bounded-length extensional propagation");
  opt.propagation(KaluzaExample::PROP_PAD,    "pad",     "fixed, maximal length string with padding characters");
  opt.propagation(KaluzaExample::PROP_OPEN);
	opt.parse(argc,argv);

  wordlength = opt.size();
	cout << "length = " << wordlength << endl;
  Script::run<KaluzaExample,DFS,SizeOptions>(opt);
	
	return 0;
}



