/*
 * Main.h
 *
 *  Created on: 2012/12/09
 *      Author: matsugen
 */

#ifndef MAIN_H_
#define MAIN_H_

class Main {
private:
	int Refresh_time;
public:
	Main();
	~Main();
	void wait();
	void update();
};

#endif /* MAIN_H_ */
