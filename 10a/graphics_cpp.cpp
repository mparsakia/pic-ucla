#include "ccc_win.h"

int ccc_win_main()
{

	Point B(-3.0, 0.0); // Left Low Corner Point
		cwin << B;

	Point C(3.0, 0.0); // Right Low Corner Point
		cwin << C;

	Line floor(B, C); // The Floor
		cwin << floor;

	Point D(-3.0, 5.0); // Top Left Wall Point
		cwin << D;

	Point E(3.0, 5.0); // Top Right wall Point
		cwin << E;

	Line celing(D, E); // The Celing (flat)
		cwin << celing;

	Line leftwall(B, D); //left wall
		cwin << leftwall;

	Line rightwall(C, E); //right wall
		cwin << rightwall;

	Point DoorLowL(-0.5, 0.0); // Lower Left Door Point
		cwin << DoorLowL;

	Point DoorLowR(0.5, 0.0); // Lower Right Door Point
		cwin << DoorLowR;

	Point DoorHiL(-0.5, 2.5); // Door Left High Point
		cwin << DoorHiL;

	Point DoorHiR(0.5, 2.5); // Door Right High Point
		cwin << DoorHiR;

	Line DoorLeft(DoorHiL, DoorLowL); // Door left Wall
		cwin << DoorLeft;

	Line DoorRight(DoorHiR, DoorLowR); // Door right wall
		cwin << DoorRight;

	Line DoorTop(DoorHiL, DoorHiR); // top of the door
		cwin << DoorTop;

	Point apex(0.0, 8.5); //apex point for roof
		cwin << apex;

	Line LeftRoof(D, apex); // left roof side
		cwin << LeftRoof;

	Line RightRoof(E, apex); // right roof side
		cwin << RightRoof;

		Point ChimTopL(-1.5, 9.0);
			cwin << ChimTopL;
		Point ChimTopR(-0.5, 9.0);
			cwin << ChimTopR;
		Point ChimLowL(-1.5, 6.8);
			cwin << ChimLowL;
		Point ChimLowR(-0.5, 7.8);
		cwin << ChimLowR;

		Line ChimTop(ChimTopL, ChimTopR);
			cwin << ChimTop;
			Line ChimLeft(ChimTopL, ChimLowL);
			cwin << ChimLeft;
			Line ChimRight(ChimTopR, ChimLowR);
			cwin << ChimRight;


	return 0;
}