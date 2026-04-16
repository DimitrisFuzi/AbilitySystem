# Unreal Ability System Prototype (C++)

A third-person prototype demonstrating **Unreal Engine C++ gameplay systems architecture** — ability slots, projectile abilities, interface-based damage, and an event-driven HUD.
Note: This is a lightweight custom ability system (not Epic’s Gameplay Ability System / GAS).
---

## Systems implemented

- **Ability system** — `UAbility` (UObject) instanced per slot via `UAbilityComponent` (UActorComponent), per-slot independent cooldowns, Blueprint-tunable via subclassing
- **Interface-based damage** — `IDamageable` UINTERFACE decouples projectile from enemy class; any actor implementing the interface can receive damage
- **Event-driven HUD** — `FOnSlotChanged` Dynamic Multicast Delegate drives slot updates; dynamic widget creation with no hard-coded slot count

---

## Quick links

- **Systems highlight video:** https://youtu.be/yPW6ly3kf84
- **Tech breakdown:** [TECHNICAL.md](Docs/TECHNICAL.md)
- **Download (Windows):** [GitHub Releases](https://github.com/DimitrisFuzi/AbilitySystem/releases/tag/v1.0.0)
- **Itch.io:** https://fouzis.itch.io/unreal-ability-system-prototype-cpp

---

## Controls

| Key | Action |
|-----|--------|
| `1` | Trigger slot 0 — Single Projectile |
| `2` | Trigger slot 1 — Burst (3 projectiles) |
| `3` / `4` | Unequipped slots (no ability assigned) |
| `WASD` | Move |
| `Mouse` | Look |
| `Escape` | Quit |

---

## Architecture overview

Abilities are `UObject` subclasses instanced per slot by `UAbilityComponent` (`UActorComponent`). Each slot holds its own ability instance with independent cooldown state. The component broadcasts an `FOnSlotChanged` delegate on equip and trigger — the HUD binds to it without the component knowing the HUD exists.

Projectile abilities spawn `AAbilityProjectile` actors which apply damage through the `IDamageable` interface — the projectile has no dependency on any specific enemy class.

See [TECHNICAL.md](Docs/TECHNICAL.md) for full implementation details and design decisions.

---

## Known limitations

- No multiplayer / replication
- No object pooling for projectiles
- Keyboard and mouse only (no controller support)
- Not broadly hardware tested

---

## What I would improve next

- Implement object pooling for projectiles
- Add a C++ base for common projectile variants (homing, bouncing) to further demonstrate the extensibility of `AAbilityProjectile`

---

## Tech stack

- Unreal Engine 5.7
- C++ + Blueprints
- Enhanced Input
- Niagara VFX
- Git + GitHub

---

## Build

- Platform: Windows
- Download: [GitHub Releases](https://github.com/DimitrisFuzi/AbilitySystem/releases/tag/v1.0.0)

---

## Credits

- **Character:** Paragon: Serath — [Epic Games](https://www.fab.com/sellers/Epic%20Games/about)
- **VFX:** Mixed Magic Spell VFX Pack — [ugurVFX](https://www.fab.com/sellers/ugurVFX/about)
- **Enemy:** Stone Golem — [buxoided](https://www.fab.com/sellers/buxoided/about)

Assets used under [Fab Standard License](https://www.fab.com/eula)
