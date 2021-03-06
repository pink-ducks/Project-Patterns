#include "pch.h"
#include <iostream>
#include <map>

class Context
{
private:
	std::map<std::string, bool> vars;
public:
	void set(const std::string& var, const bool value)
	{
		vars.insert(std::pair<std::string, bool>(var, value));
	}

	bool get(const std::string& exp)
	{
		return vars[exp];
	}
};

class AbstractExpression // SYMBOL
{
public:
	virtual ~AbstractExpression() {}

	virtual bool interpret(Context* const)
	{
		return false;
	}
};

// TERMINAL
class TerminalExpression : public AbstractExpression
{
public:
	TerminalExpression(const std::string& val) : value(val) {}

	~TerminalExpression() {}

	bool interpret(Context* const context)
	{
		return context->get(value);
	}

private:
	std::string value;
};
// NIETERMINAL
class NonterminalExpression : public AbstractExpression
{
private:
	AbstractExpression *lop;
	AbstractExpression *rop;
public:
	NonterminalExpression(AbstractExpression *left, AbstractExpression *right) :
		lop(left), rop(right) {}

	~NonterminalExpression()
	{
		delete lop;
		delete rop;
	}

	bool interpret(Context *const context)
	{
		return lop->interpret(context) && rop->interpret(context);
	}
};


int main()
{
	// An example of very simple expression tree
	// that corresponds to expression (A AND B)
	AbstractExpression *A = new TerminalExpression("A");
	AbstractExpression *B = new TerminalExpression("B");
	AbstractExpression *exp = new NonterminalExpression(A, B);

	Context context;
	context.set("A", true);
	context.set("B", false);

	std::cout << context.get("A") << " AND " << context.get("B");
	std::cout << " = " << exp->interpret(&context) << std::endl;

	delete exp;
	return 0;
}