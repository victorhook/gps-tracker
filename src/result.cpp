#include "result.h"

const String resultToString(const result_t result) {
    String str;

    switch (result) {
        case RESULT_OK:
            str = "OK";
            break;
        default:
            str = "Unknown";
            break;
    }

    return str;
}