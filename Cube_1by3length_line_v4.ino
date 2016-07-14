/*
  by Betsuin
  June 2016
  centre point with off sets left right
  centre left right have a +1 or -1 step in xyz
*/

#include "Cube.h"

//  First Line
int xc = 3;
int yc = 1;
int zc = 2;
int xcr = 2;
int ycr = 2;
int zcr = 2;
int xcl = 1;
int ycl = 0;
int zcl = 1;
int xcstep = -1;
int ycstep = 1;
int zcstep = 1;
int xclstep = 1;
int yclstep = 1;
int zclstep = -1;
int xcrstep = 1;
int ycrstep = 1;
int zcrstep = 1;
int colourwheel = 1;
int colourwheel1 = 2;
int colourwheel2 = 3;

//  Second Line
int xc_l2 = 2;
int yc_l2 = 3;
int zc_l2 = 1;
int xcr_l2 = 1;
int ycr_l2 = 1;
int zcr_l2 = 3;
int xcl_l2 = 2;
int ycl_l2 = 1;
int zcl_l2 = 0;
int xcstep_l2 = -1;
int ycstep_l2 = -1;
int zcstep_l2 = 1;
int xclstep_l2 = -1;
int yclstep_l2 = 1;
int zclstep_l2 = 1;
int xcrstep_l2 = 1;
int ycrstep_l2 = -1;
int zcrstep_l2 = 1;
int colourwheel_l2 = 7;
int colourwheel1_l2 = 2;
int colourwheel2_l2 = 1;

//  Third Line
int xc_l3 = 3;
int yc_l3 = 1;
int zc_l3 = 2;
int xcr_l3 = 2;
int ycr_l3 = 2;
int zcr_l3 = 2;
int xcl_l3 = 1;
int ycl_l3 = 0;
int zcl_l3 = 1;
int xcstep_l3 = -1;
int ycstep_l3 = 1;
int zcstep_l3 = 1;
int xclstep_l3 = 1;
int yclstep_l3 = 1;
int zclstep_l3 = -1;
int xcrstep_l3 = 1;
int ycrstep_l3 = 1;
int zcrstep_l3 = 1;
int colourwheel_l3 = 5;
int colourwheel1_l3 = 2;
int colourwheel2_l3 = 6;


//int centre_step = 0;

rgb_t linecolour[] = {BLUE, GREEN, ORANGE, PINK, PURPLE, RED, WHITE, YELLOW};

// the following set up code for the serial port was written by someone else...
Cube cube;
void setup(void) {
  // Serial port options for control of the Cube using serial commands are:
  // 0: Control via the USB connector (most common).
  // 1: Control via the RXD and TXD pins on the main board.
  // -1: Don't attach any serial port to interact with the Cube.
  cube.begin(0, 115200); // Start on serial port 0 (USB) at 115200 baud
  byte waitCounter = 0;
  while (waitCounter < 30 && !Serial) {
    delay(100);
    waitCounter++;
  }
}

void loop(void) {    // top curly bracket  ##########

  // line original
  if (random(1, 300) == 2)  colourwheel = random(1, 8);
  if (random(1, 300) == 2)  colourwheel1 = random(1, 8);
  if (random(1, 300) == 2)  colourwheel2 = random(1, 8);

  // line 2
  if (random(1, 300) == 2)  colourwheel_l2 = random(1, 8);
  if (random(1, 300) == 2)  colourwheel1_l2 = random(1, 8);
  if (random(1, 300) == 2)  colourwheel2_l2 = random(1, 8);

  // line 3
  if (random(1, 300) == 2)  colourwheel_l3 = random(1, 8);
  if (random(1, 300) == 2)  colourwheel1_l3 = random(1, 8);
  if (random(1, 300) == 2)  colourwheel2_l3 = random(1, 8);

  /* old sanity check
    if (xl > 3) xl = 3;
    if (yl > 3) yl = 3;
    if (zl > 3) zl = 3;
    if (xr > 3) xr = 3;
    if (yr > 3) yr = 3;
    if (zr > 3) zr = 3;

    if (xl < 0) xl = 0;
    if (yl < 0) yl = 0;
    if (zl < 0) zl = 0;
    if (xr < 0) xr = 0;
    if (yr < 0) yr = 0;
    if (zr < 0) zr = 0;
  */

  cube.all(BLACK);

  // If you want serial port variable print out

  //Serial.print("xc:"); Serial.print(xc);
  // Serial.print("xcstep:"); Serial.print(xcstep);
  //Serial.print(" yc:"); Serial.print(yc);
  //  Serial.print("ycstep:"); Serial.print(ycstep);
  // Serial.print(" zc:"); Serial.println(zc);
  //  Serial.print("zcstep:"); Serial.println(zcstep);
  //  Serial.print(" yl:"); Serial.print(yl);
  //  Serial.print(" zr:"); Serial.print(zr);
  // Serial.print(" zl:"); Serial.println(zl);

  // not using line gonna use set
  // cube.line(xr, yr, zr, xl, yl, zl, linecolour[colourwheel]);

  // sanity check cubeset variables otherwise cubeline crashes does this?
  if (xc > 3) xc = 3;
  if (yc > 3) yc = 3;
  if (zc > 3) zc = 3;
  if (xc < 0) xc = 0;
  if (yc < 0) yc = 0;
  if (zc < 0) zc = 0;
  if (xcl > 3) xcl = 3;
  if (ycl > 3) ycl = 3;
  if (zcl > 3) zcl = 3;
  if (xcl < 0) xcl = 0;
  if (ycl < 0) ycl = 0;
  if (zcl < 0) zcl = 0;
  if (xcr > 3) xcr = 3;
  if (ycr > 3) ycr = 3;
  if (zcr > 3) zcr = 3;
  if (xcr < 0) xcr = 0;
  if (ycr < 0) ycr = 0;
  if (zcr < 0) zcr = 0;

  // draw the line
  cube.set(xc, yc, zc, RED);
  // cube.set(xcl, ycl, zcl, linecolour[colourwheel1]);
  // cube.set(xcr, ycr, zcr, linecolour[colourwheel2]);
  cube.set(xcl, ycl, zcl, RED);
  cube.set(xcr, ycr, zcr, RED);

  // line 2 sanity check cubeset variables otherwise cubeline crashes does this?
  if (xc_l2 > 3) xc_l2 = 3;
  if (yc_l2 > 3) yc_l2 = 3;
  if (zc_l2 > 3) zc_l2 = 3;
  if (xc_l2 < 0) xc_l2 = 0;
  if (yc_l2 < 0) yc_l2 = 0;
  if (zc_l2 < 0) zc_l2 = 0;
  if (xcl_l2 > 3) xcl_l2 = 3;
  if (ycl_l2 > 3) ycl_l2 = 3;
  if (zcl_l2 > 3) zcl_l2 = 3;
  if (xcl_l2 < 0) xcl_l2 = 0;
  if (ycl_l2 < 0) ycl_l2 = 0;
  if (zcl_l2 < 0) zcl_l2 = 0;
  if (xcr_l2 > 3) xcr_l2 = 3;
  if (ycr_l2 > 3) ycr_l2 = 3;
  if (zcr_l2 > 3) zcr_l2 = 3;
  if (xcr_l2 < 0) xcr_l2 = 0;
  if (ycr_l2 < 0) ycr_l2 = 0;
  if (zcr_l2 < 0) zcr_l2 = 0;

  // draw the line 2
  cube.set(xc_l2, yc_l2, zc_l2, GREEN);
  // cube.set(xcl_l2, ycl_l2, zcl_l2, linecolour[colourwheel1_l2]);
  // cube.set(xcr_l2, ycr_l2, zcr_l2, linecolour[colourwheel2_l2]);
  cube.set(xcl_l2, ycl_l2, zcl_l2, GREEN);
  cube.set(xcr_l2, ycr_l2, zcr_l2, GREEN);

  // line 3 sanity check cubeset variables otherwise cubeline crashes does this?
  if (xc_l3 > 3) xc_l3 = 3;
  if (yc_l3 > 3) yc_l3 = 3;
  if (zc_l3 > 3) zc_l3 = 3;
  if (xc_l3 < 0) xc_l3 = 0;
  if (yc_l3 < 0) yc_l3 = 0;
  if (zc_l3 < 0) zc_l3 = 0;
  if (xcl_l3 > 3) xcl_l3 = 3;
  if (ycl_l3 > 3) ycl_l3 = 3;
  if (zcl_l3 > 3) zcl_l3 = 3;
  if (xcl_l3 < 0) xcl_l3 = 0;
  if (ycl_l3 < 0) ycl_l3 = 0;
  if (zcl_l3 < 0) zcl_l3 = 0;
  if (xcr_l3 > 3) xcr_l3 = 3;
  if (ycr_l3 > 3) ycr_l3 = 3;
  if (zcr_l3 > 3) zcr_l3 = 3;
  if (xcr_l3 < 0) xcr_l3 = 0;
  if (ycr_l3 < 0) ycr_l3 = 0;
  if (zcr_l3 < 0) zcr_l3 = 0;

  // draw the line 3
  cube.set(xc_l3, yc_l3, zc_l3, BLUE);
  // cube.set(xcl_l3, ycl_l3, zcl_l3, linecolour[colourwheel1_l3]);
  // cube.set(xcr_l3, ycr_l3, zcr_l3, linecolour[colourwheel2_l3]);
  cube.set(xcl_l3, ycl_l3, zcl_l3, BLUE);
  cube.set(xcr_l3, ycr_l3, zcr_l3, BLUE);

  // move the line centre but keep it in the cube confines
  if ((xc + xcstep) > 3) xc = 3;
  else if ((xc + xcstep) < 0) xc = 0;
  else xc = xc + xcstep;

  if ((yc + ycstep) > 3) yc = 3;
  else if ((yc + ycstep) < 0) yc = 0;
  else yc = yc + ycstep;

  if ((zc + zcstep) > 3) zc = 3;
  else if ((zc + zcstep) < 0) zc = 0;
  else zc = zc + zcstep;

  // move the line 2 centre but keep it in the cube confines
  if ((xc_l2 + xcstep_l2) > 3) xc_l2 = 3;
  else if ((xc_l2 + xcstep_l2) < 0) xc_l2 = 0;
  else xc_l2 = xc_l2 + xcstep_l2;

  if ((yc_l2 + ycstep_l2) > 3) yc_l2 = 3;
  else if ((yc_l2 + ycstep_l2) < 0) yc_l2 = 0;
  else yc_l2 = yc_l2 + ycstep_l2;

  if ((zc_l2 + zcstep_l2) > 3) zc_l2 = 3;
  else if ((zc_l2 + zcstep_l2) < 0) zc_l2 = 0;
  else zc_l2 = zc_l2 + zcstep_l2;

  // move the line 3 centre but keep it in the cube confines
  if ((xc_l3 + xcstep_l3) > 3) xc_l3 = 3;
  else if ((xc_l3 + xcstep_l3) < 0) xc_l3 = 0;
  else xc_l3 = xc_l3 + xcstep_l3;

  if ((yc_l3 + ycstep_l3) > 3) yc_l3 = 3;
  else if ((yc_l3 + ycstep_l3) < 0) yc_l3 = 0;
  else yc_l3 = yc_l3 + ycstep_l3;

  if ((zc_l3 + zcstep_l3) > 3) zc_l3 = 3;
  else if ((zc_l3 + zcstep_l3) < 0) zc_l3 = 0;
  else zc_l3 = zc_l3 + zcstep_l3;


  // left and right points, sanity check above keeps on the cube
  xcr = xc + xcrstep;
  ycr = yc + ycrstep;
  zcr = zc + zcrstep;

  xcl = xc + xclstep;
  ycl = yc + yclstep;
  zcl = zc + zclstep;


  // left and right points line 2, sanity check above keeps on the cube
  xcr_l2 = xc_l2 + xcrstep_l2;
  ycr_l2 = yc_l2 + ycrstep_l2;
  zcr_l2 = zc_l2 + zcrstep_l2;

  xcl_l2 = xc_l2 + xclstep_l2;
  ycl_l2 = yc_l2 + yclstep_l2;
  zcl_l2 = zc_l2 + zclstep_l2;

  // left and right points line 3, sanity check above keeps on the cube
  xcr_l3 = xc_l3 + xcrstep_l3;
  ycr_l3 = yc_l3 + ycrstep_l3;
  zcr_l3 = zc_l3 + zcrstep_l3;

  xcl_l3 = xc_l3 + xclstep_l3;
  ycl_l3 = yc_l3 + yclstep_l3;
  zcl_l3 = zc_l3 + zclstep_l3;

  // randomly set centre direction line original
  if (random(0, 4) == 2) {
    switch (random(0, 3)) {
      case 0:
        xcstep = 0;
        break;
      case 1:
        xcstep = 1;
        break;
      case 2:
        xcstep = -1;
        break;
    }
  }
  if (random(0, 4) == 2) {
    switch (random(0, 3)) {
      case 0:
        ycstep = 0;
        break;
      case 1:
        ycstep = 1;
        break;
      case 2:
        ycstep = -1;
        break;
    }
  }
  if (random(0, 4) == 2) {
    switch (random(0, 3)) {
      case 0:
        zcstep = 0;
        break;
      case 1:
        zcstep = -1;
        break;
      case 2:
        zcstep = 1;
        break;
    }
  }
  // randomly set centre direction line original --- Bottom


  // randomly set centre direction line 2
  if (random(0, 4) == 2) {
    switch (random(0, 3)) {
      case 0:
        xcstep_l2 = 0;
        break;
      case 1:
        xcstep_l2 = 1;
        break;
      case 2:
        xcstep_l2 = -1;
        break;
    }
  }
  if (random(0, 4) == 2) {
    switch (random(0, 3)) {
      case 0:
        ycstep_l2 = 0;
        break;
      case 1:
        ycstep_l2 = 1;
        break;
      case 2:
        ycstep_l2 = -1;
        break;
    }
  }
  if (random(0, 4) == 2) {
    switch (random(0, 3)) {
      case 0:
        zcstep_l2 = 0;
        break;
      case 1:
        zcstep_l2 = -1;
        break;
      case 2:
        zcstep_l2 = 1;
        break;
    }
  }
  // randomly set centre direction line 2 --- Bottom

  // randomly set centre direction line 3
  if (random(0, 4) == 2) {
    switch (random(0, 3)) {
      case 0:
        xcstep_l3 = 0;
        break;
      case 1:
        xcstep_l3 = 1;
        break;
      case 2:
        xcstep_l3 = -1;
        break;
    }
  }
  if (random(0, 4) == 2) {
    switch (random(0, 3)) {
      case 0:
        ycstep_l3 = 0;
        break;
      case 1:
        ycstep_l3 = 1;
        break;
      case 2:
        ycstep_l3 = -1;
        break;
    }
  }
  if (random(0, 4) == 2) {
    switch (random(0, 3)) {
      case 0:
        zcstep_l3 = 0;
        break;
      case 1:
        zcstep_l3 = -1;
        break;
      case 2:
        zcstep_l3 = 1;
        break;
    }
  }
  // randomly set centre direction line 3 --- Bottom



  // randomly set left and rights line original
  if (random(0, 3) == 1) {
    if (xclstep > 0) xclstep = -1;
    else xclstep = 1;
  };
  if (random(0, 3) == 1) {
    if (yclstep > 0) yclstep = -1;
    else yclstep = 1;
  };
  if (random(0, 3) == 1) {
    if (zclstep > 0) zclstep = -1;
    else zclstep = 1;
  };
  if (random(0, 3) == 1) {
    if (xcrstep > 0) xcrstep = -1;
    else xcrstep = 1;
  };
  if (random(0, 3) == 1) {
    if (ycrstep > 0) ycrstep = -1;
    else ycrstep = 1;
  };
  if (random(0, 3) == 1) {
    if (zcrstep > 0) zcrstep = -1;
    else zcrstep = 1;
  };
  // randomly set left and rights line original ---- BOTTOM


  // randomly set left and rights line 2
  if (random(0, 3) == 1) {
    if (xclstep_l2 > 0) xclstep_l2 = -1;
    else xclstep_l2 = 1;
  };
  if (random(0, 3) == 1) {
    if (yclstep_l2 > 0) yclstep_l2 = -1;
    else yclstep_l2 = 1;
  };
  if (random(0, 3) == 1) {
    if (zclstep_l2 > 0) zclstep_l2 = -1;
    else zclstep_l2 = 1;
  };
  if (random(0, 3) == 1) {
    if (xcrstep_l2 > 0) xcrstep_l2 = -1;
    else xcrstep_l2 = 1;
  };
  if (random(0, 3) == 1) {
    if (ycrstep_l2 > 0) ycrstep_l2 = -1;
    else ycrstep_l2 = 1;
  };
  if (random(0, 3) == 1) {
    if (zcrstep_l2 > 0) zcrstep_l2 = -1;
    else zcrstep_l2 = 1;
  };
  // randomly set left and rights line 2 ---- BOTTOM

  // randomly set left and rights line 3
  if (random(0, 3) == 1) {
    if (xclstep_l3 > 0) xclstep_l3 = -1;
    else xclstep_l3 = 1;
  };
  if (random(0, 3) == 1) {
    if (yclstep_l3 > 0) yclstep_l3 = -1;
    else yclstep_l3 = 1;
  };
  if (random(0, 3) == 1) {
    if (zclstep_l3 > 0) zclstep_l3 = -1;
    else zclstep_l3 = 1;
  };
  if (random(0, 3) == 1) {
    if (xcrstep_l3 > 0) xcrstep_l3 = -1;
    else xcrstep_l3 = 1;
  };
  if (random(0, 3) == 1) {
    if (ycrstep_l3 > 0) ycrstep_l3 = -1;
    else ycrstep_l3 = 1;
  };
  if (random(0, 3) == 1) {
    if (zcrstep_l3 > 0) zcrstep_l3 = -1;
    else zcrstep_l3 = 1;
  };
  // randomly set left and rights line 3 ---- BOTTOM

  delay(85);

  // bottom curly bracket  ##########
}

