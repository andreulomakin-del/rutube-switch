
#include <switch.h>
#include <cstdio>

int main(int argc, char* argv[]) {
    consoleInit(NULL);

    printf("\x1b[1;31mRUTUBE for Nintendo Switch\x1b[0m\n");
    printf("--------------------------------\n\n");
    printf("Opening RUTUBE...\n");

    WebCommonConfig config;

    Result rc = webPageCreate(&config, "https://rutube.ru/");

    if (R_SUCCEEDED(rc)) {
        rc = webConfigSetWhitelist(
            &config,
            "^https?://([0-9A-Za-z-]+\\.)*rutube\\.ru($|/)"
        );
    }

    if (R_SUCCEEDED(rc)) {
        rc = webConfigShow(&config, NULL);
    }

    if (R_FAILED(rc)) {
        printf("\nWebApplet error: 0x%08X\n", rc);
        printf("Check firmware and Atmosphere compatibility.\n");
    }

    consoleExit(NULL);
    return 0;
}
