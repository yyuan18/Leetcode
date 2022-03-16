/**
 * Question: Clock angle problem
 * 
 * Author Yifan Yuan
 * Date 2022-03-15
 * Description: 
 * Find angle between the hands of an analog clock at any given time
 * 
 * Input:  hour: 12, min: 30
 * Output: 165 degree
 * 
 * Source: GeeksforGeeks
 */

// Two hands coincide with each other 22 times a day
// Start with 0:00

int calcAngle(double h, double m) {
    if (h < 0 || m < 0 || h > 12 || m > 60) {
        printf("Wrong Input");
    }

    if (h == 12) h = 0;
    if (m == 60) {
        m = 0;
        h += 1;
        if (h >= 12) {
            h = h - 12;
        }
    }

    // Hour hand: 360 degree in 12 hours, 0.5 degree per min
    // Min hand:  360 degree in 60 mins, 6 degree per min
    float hour_angle = 0.5 * (60 * h + m);
    float min_angle = 6 * m;

    float angle = abs(hour_angle - min_angle);
    angle = min(360 - angle, angle);

    return angle;
}