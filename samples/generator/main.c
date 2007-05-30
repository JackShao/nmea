#include <nmea/nmea.h>
#include <windows.h>
#include <stdio.h>

int main()
{
    nmeaGENERATOR *gen;
    nmeaINFO info;
    char buff[2048];
    int gen_sz;
    int it;

    nmea_zero_INFO(&info);

    if(0 == (gen = nmea_create_generator(NMEA_GEN_ROTATE, &info)))
        return -1;

    for(it = 0; it < 10; ++it)
    {
        gen_sz = nmea_generate_from(
            &buff[0], 2048, &info, gen,
            GPGGA | GPGSA | GPGSV | GPRMC | GPVTG
            );

        buff[gen_sz] = 0;
        printf("%s\n", &buff[0]);

        Sleep(500);
    }

    nmea_gen_destroy(gen);

    return 0;
}
