# RUTUBE for Nintendo Switch — MVP 0.1

## Cloud build (no PC required)

This repository includes a GitHub Actions workflow that builds the `.nro` with the official `devkitpro/devkita64` toolchain container.

1. Create a GitHub repository named `rutube-switch`.
2. Upload the contents of this project ZIP to the repository, keeping the `.github/workflows/build.yml` path intact.
3. Open the repository's **Actions** tab.
4. Select **Build RUTUBE for Nintendo Switch** and press **Run workflow**, or push a commit.
5. When the run finishes successfully, open it and download the `rutube-switch-nro` artifact ZIP.
6. Extract `rutube_switch.nro` and copy it to `SD:/switch/rutube_switch/rutube_switch.nro`.

## What this prototype does

- Builds as `rutube_switch.nro`.
- Opens the official RUTUBE website in the Switch WebApplet.
- Uses RUTUBE's own web player; availability, ads and restrictions remain controlled by RUTUBE.
- Does not download videos, bypass DRM, or extract protected streams.

This is a compatibility prototype, not yet a custom catalog/search UI.

## Build locally

If you later have a PC with devkitPro installed:

```bash
make
```

## Compatibility

The Switch WebApplet has firmware- and launch-mode-dependent restrictions. Homebrew browser applets may fail on some Atmosphère/firmware combinations. If it fails, send the exact error/result code and your Switch firmware + Atmosphère version.

For the first test, launch hbmenu in Application mode (hold R while launching a game, then open hbmenu), not Applet mode.

## Next development stage

After confirming that the WebApplet opens and RUTUBE playback works on the console, the next version can add a native controller-friendly catalog/search screen. RUTUBE's public website API is unofficial/undocumented and may change, so playback initially stays inside the official player flow.

## Validation status

The workflow and project files are prepared, but the build has not yet run in GitHub Actions and has not been tested on a physical Switch.
