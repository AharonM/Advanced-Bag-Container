#ifndef BAG_EXCEPTION_H
#define BAG_EXCEPTION_H

#include <iostream>
#include <string>

class BagException {
	friend std::ostream &operator <<(std::ostream &os, const BagException &e) {
		os << "*** BagException *** " << e.message;
		return os;
	}
public:
	BagException(std::string message) : message(message) {}
private:
	 std::string message;
};

#endif
