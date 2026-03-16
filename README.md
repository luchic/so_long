# Project Structure

This document describes the folder and file structure of the project.

```
includes/
    so_long.h
    so_long_types.h

src/
    main.c

    core/
        init_game.c
        free_game.c
        error.c
        close.c

    parsing/
        read_map.c
        parse_map.c
        parse_utils.c

    validation/
        validate_map.c
        validate_chars.c
        validate_shape.c
        validate_path.c
        flood_fill.c

    render/
        load_assets.c
        draw_map.c
        redraw.c

    game/
        input.c
        move_player.c
        move_utils.c
        win.c
```
