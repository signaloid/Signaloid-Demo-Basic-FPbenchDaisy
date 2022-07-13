/*
 *	:name "carthesianToPolar, radius"
 *	:pre (and (<= 1 x 100) (<= 1 y 100))
 *	:spec (hypot x y)
 */
double ex0(double x, double y);

/*
 *	:name "carthesianToPolar, theta"
 *	:pre (and (<= 1 x 100) (<= 1 y 100))
 *	:spec (* (atan2 y x) (/ 180 PI))
 */
double ex1(double x, double y);

/*
 *	:name "polarToCarthesian, x"
 *	:pre (and (<= 1 radius 10) (<= 0 theta 360))
 *	:spec (* radius (cos (* theta (/ 180 PI))))
 */
double ex2(double radius, double theta);

/*
 *	:name "polarToCarthesian, y"
 *	:pre (and (<= 1 radius 10) (<= 0 theta 360))
 *	:spec (* radius (sin (* theta (/ 180 PI))))
 */
double ex3(double radius, double theta);

/*
 *	:name "instantaneousCurrent"
 *	:pre (and (<= 0 t 300.0) (<= 1 resistance 50) (<= 1 frequency 100)
 *		(<= 0.001 inductance 0.004) (<= 1 maxVoltage 12))
 */
double ex4(double t, double resistance, double frequency, double inductance, double maxVoltage);

/*
 *	:name "matrixDeterminant"
 *	:pre (and (<= -10 a 10) (<= -10 b 10) (<= -10 c 10)
 *		(<= -10 d 10) (<= -10 e 10) (<= -10 f 10)
 *		(<= -10 g 10) (<= -10 h 10) (<= -10 i 10))
 */
double ex5(double a, double b, double c, double d, double e, double f, double g, double h, double i);

/*
 *	:name "matrixDeterminant2"
 *	:pre (and (<= -10 a 10) (<= -10 b 10) (<= -10 c 10)
 *	          (<= -10 d 10) (<= -10 e 10) (<= -10 f 10)
 *	          (<= -10 g 10) (<= -10 h 10) (<= -10 i 10))
 */
double ex6(double a, double b, double c, double d, double e, double f, double g, double h, double i);

