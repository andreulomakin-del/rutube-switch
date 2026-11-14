#include <switch.h>
#include <cstdio>

int main(int argc, char* argv[]) {
    consoleInit(NULL);

    printf("\x1b[1;31mRUTUBE for Nintendo Switch\x1b[0m\n");
    printf("--------------------------------\n\n");
    printf("Opening the official RUTUBE website...\n");
    printf("The video player is provided by RUTUBE.\n\n");
    printf("Press + to exit after returning from the browser.\n");

    // webNewsCreate automatically adds the initial domain to the WebApplet
    // whitelist. This is a lightweight first prototype: official RUTUBE UI
    // and player are used, rather than extracting or bypassing media streams.
    WebCommonConfig config;
    Result rc = webPageCreate(&config, "https://rutube.ru/");

    if (R_SUCCEEDED(rc)) {
        rc = webConfigShow(&config, NULL);
    }

    if (R_FAILED(rc)) {
        printf("\nCould not launch the Switch web applet.\n");
        printf("Result: 0x%08X\n", rc);
        printf("\nThis can depend on firmware / Atmosphere compatibility.\n");
    } else {
        printf("\nRUTUBE session closed.\n");
    }

    while (appletMainLoop()) {
        hidScanInput();
        if (hidKeysDown(CONTROLLER_P1_AUTO) & KEY_PLUS) break;
        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
