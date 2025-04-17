#include "List.h"

int main() {
	{
		List a;
		a.Print();
		a.PrintReverse();
		std::cout << '\n';

		List b(2);
		b.Print();
		b.PrintReverse();
		std::cout << '\n';
		b.Add(8);
		b.Add(16);
		b.Add(32);
		b.Add(64);
		b.Print();
		b.PrintReverse();
		std::cout << '\n';

		a.Add(1);
		a.Print();
		a.PrintReverse();
		std::cout << '\n';

		a.AddBefore(2, 0);
		a.Print();
		a.PrintReverse();
		std::cout << '\n';

		a.AddAfter(3, 10);
		a.Print();
		a.PrintReverse();
		std::cout << '\n';

		List c(a);
		c.Print();
		c.PrintReverse();
		std::cout << '\n';

		List d(std::move(b));
		d.Print();
		d.PrintReverse();
		std::cout << '\n';

		List e;
		e = a;
		e.Print();
		e.PrintReverse();
		std::cout << '\n';

		List f;
		f = std::move(e);
		f.Print();
		f.PrintReverse();
		std::cout << '\n';

		a.Delete(1);
		a.Print();
		a.PrintReverse();
		std::cout << '\n';

		c.Add(2);
		c.Print();
		c.PrintReverse();
		std::cout << '\n';

		c.DeleteAllWithVal(2);
		c.Print();
		c.PrintReverse();
		std::cout << '\n';

		c.Clear();
		c.Print();
		c.PrintReverse();
		std::cout << '\n';

		bool emp = c.IsEmpty();
		std::cout << emp;
		std::cout << '\n';

		std::fstream file1("test.txt", std::fstream::out);
		file1 << d;
		file1.close();

		List g;
		g.Print();
		g.PrintReverse();
		std::cout << '\n';

		std::fstream file2("test.txt", std::fstream::in);
		file2 >> g;

		g.Print();
		g.PrintReverse();
		std::cout << '\n';
		file2.close();
	}

	return 0;
}