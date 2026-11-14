#
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
        // Allow RUTUBE and its subdomains.
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
        printf("Press any key to close.\n");
        consoleUpdate(NULL);
        while (appletMainLoop()) {
            hidScanInput();
            if (hidKeysDown(CONTROLLER_P1_AUTO)) break;
        }
    }

    consoleExit(NULL);
    ret
        urn 0;
}
