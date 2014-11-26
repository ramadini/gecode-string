#include <gecode/flatzinc.hh>
#include <gecode/flatzinc/registry.hh>

namespace Gecode { namespace FlatZinc {
	
	bool isIntVar(FlatZincSpace& s, AST::Node* n){
		return n->isIntVar();
	}
	bool isBoolVar(FlatZincSpace& s, AST::Node* n){
		return n->isBoolVar();
	}
	bool isInt(FlatZincSpace& s, AST::Node* n){
		return n->isInt();
	}
	bool isBool(FlatZincSpace& s, AST::Node* n){
		return n->isBool();
	}
	bool isSet(FlatZincSpace& s, AST::Node* n){
		return n->isSet();
	}
	bool isIntVarArray(FlatZincSpace& s, AST::Node* n){
		if(!n->isArray())return false;
		AST::Array* a = n->getArray();
		if (a->a.size() == 0)return true;
		for(int i=a->a.size(); i--;) {
			if (!(a->a[i]->isIntVar() || a->a[i]->isInt())) return false;
		}
		return true;
	}
	bool isBoolVarArray(FlatZincSpace& s, AST::Node* n){
		if(!n->isArray())return false;
		AST::Array* a = n->getArray();
		if (a->a.size() == 0)return true;
		for(int i=a->a.size(); i--;) {
			if (!(a->a[i]->isBoolVar() || a->a[i]->isBool() || (a->a[i]->isIntVar() && s.aliasBool2Int(a->a[i]->getIntVar()) != -1))) return false;
		}
		return true;
	}
	bool isIntArray(FlatZincSpace& s, AST::Node* n){
		if(!n->isArray())return false;
		AST::Array* a = n->getArray();
		if (a->a.size() == 0)return true;
		for(int i=a->a.size(); i--;) {
			if (!(a->a[i]->isInt())) return false;
		}
		return true;
	}
	bool isBoolArray(FlatZincSpace& s, AST::Node* n){
		if(!n->isArray())return false;
		AST::Array* a = n->getArray();
		if (a->a.size() == 0)return true;
		for(int i=a->a.size(); i--;) {
			if (!(a->a[i]->isBool())) return false;
		}
		return true;
	}
	bool isSetArray(FlatZincSpace& s, AST::Node* n){
		if(!n->isArray())return false;
		AST::Array* a = n->getArray();
		if (a->a.size() == 0)return true;
		for(int i=a->a.size(); i--;) {
			if (!(a->a[i]->isSet())) return false;
		}
		return true;
	}
	


	int getInt(AST::Node* n){
		return n->getInt();
	}
	bool getBool(AST::Node* n){
		return n->getBool();
	}
   
}}

