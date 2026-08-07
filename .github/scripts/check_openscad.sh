#!/usr/bin/env bash
set -euo pipefail

if ! command -v openscad >/dev/null 2>&1; then
  echo "OpenSCAD ontbreekt; installeer het pakket 'openscad' en voer deze controle opnieuw uit." >&2
  exit 2
fi

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
output_dir="$(mktemp -d -t curious-openscad-XXXXXX)"
trap 'rm -rf -- "$output_dir"' EXIT

render_model() {
  local name="$1"
  local source="$2"
  shift 2

  local log="$output_dir/$name.log"
  local stl="$output_dir/$name.stl"

  if ! QT_QPA_PLATFORM=offscreen openscad \
      --hardwarnings \
      --check-parameters=true \
      --check-parameter-ranges=true \
      --export-format binstl \
      "$@" \
      -o "$stl" \
      "$repo_root/$source" >"$log" 2>&1; then
    echo "OpenSCAD-render mislukt: $name" >&2
    cat "$log" >&2
    return 1
  fi

  if grep -Eq '(^|EXPORT-)WARNING:|ERROR:' "$log"; then
    echo "OpenSCAD meldde een waarschuwing of fout: $name" >&2
    cat "$log" >&2
    return 1
  fi

  if ! grep -Eq 'Simple:[[:space:]]+yes' "$log"; then
    echo "OpenSCAD bevestigde geen eenvoudige manifold mesh: $name" >&2
    cat "$log" >&2
    return 1
  fi

  if [[ ! -s "$stl" ]]; then
    echo "OpenSCAD maakte geen bruikbare STL: $name" >&2
    return 1
  fi

  echo "$name: geldige manifold STL"
}

render_model \
  "penhouder-zwaartekracht-hoorn" \
  "projects/arm-pen-plotter/pen_holder.scad"

render_model \
  "penhouder-veer-vlak" \
  "projects/arm-pen-plotter/pen_holder.scad" \
  -D 'float_mode="spring"' \
  -D 'mount_mode="flat"'

render_model \
  "polsinterface-standaard" \
  "projects/effector-mount/mount_standard.scad"

render_model \
  "polsinterface-zonder-naaf-of-nok" \
  "projects/effector-mount/mount_standard.scad" \
  -D 'horn_hub_d=0' \
  -D 'key_notch=false'

render_model \
  "magneetgereedschap" \
  "projects/effector-mount/magnet_tool.scad"

render_model \
  "spelingmunt-standaard" \
  "projects/tolerance-test-coin/tolerance-test-coin.scad"

render_model \
  "spelingmunt-korte-reeks" \
  "projects/tolerance-test-coin/tolerance-test-coin.scad" \
  -D 'clear_min=0.15' \
  -D 'clear_max=0.35' \
  -D 'clear_step=0.10' \
  -D 'n_pins=1'

render_model \
  "grijper-mg996r-open" \
  "projects/effector-mount/gripper.scad"

render_model \
  "grijper-mg90s-dicht" \
  "projects/effector-mount/gripper.scad" \
  -D 'servo_type="MG90S"' \
  -D 'preview_open=false' \
  -D 'tpu_pad=false'

echo "Alle OpenSCAD-varianten zijn zonder waarschuwingen gerenderd."
