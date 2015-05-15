#ifndef CONFIG_H
#define CONFIG_H

#ifdef __linux__
    #define CLEAR "clear"
    #define PAUSE "echo 'Veuillez appuyer sur entré pour continuer...'; read"
#else
    #define CLEAR "cls"
    #define PAUSE "pause"
#endif

/*
 * La fonction to_string() est ambigue sous VC++2010. Ce define devrait
 * contourner ce problème.
 *
 * https://connect.microsoft.com/VisualStudio/feedback/details/742642
 */
#define to_string(STR) to_string(static_cast<long long>(STR))

#endif
