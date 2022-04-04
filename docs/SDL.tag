<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.9.2" doxygen_gitid="da0a6b42c349bc06b2804a4b0e8f55c7690f5cf9">
  <compound kind="file">
    <name>affichage_sdl.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>d8/d1b/affichage__sdl_8h.html</filename>
    <member kind="function">
      <type>int</type>
      <name>afficher_menu</name>
      <anchorfile>d8/d1b/affichage__sdl_8h.html</anchorfile>
      <anchor>a0a86720440ed48cd84f9bda8b7ca10f6</anchor>
      <arglist>(char menu[4][30])</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>affichage_dialogue</name>
      <anchorfile>d8/d1b/affichage__sdl_8h.html</anchorfile>
      <anchor>a38dc84bd7da8d9d381981d966f4c7b8d</anchor>
      <arglist>(char *id_PNJ)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>audio.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>da/d09/audio_8h.html</filename>
    <class kind="struct">Audio</class>
    <member kind="function">
      <type>Audio *</type>
      <name>createAudio</name>
      <anchorfile>da/d09/audio_8h.html</anchorfile>
      <anchor>a83eb6efb3d674325c1377daf30c54883</anchor>
      <arglist>(const char *filename, uint8_t loop, int volume)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>freeAudio</name>
      <anchorfile>da/d09/audio_8h.html</anchorfile>
      <anchor>aa3730ab77fa3498af628a47bbe29fac0</anchor>
      <arglist>(Audio *audio)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>playSound</name>
      <anchorfile>da/d09/audio_8h.html</anchorfile>
      <anchor>aa2a1c236a8c22740fd92902a1929f36d</anchor>
      <arglist>(const char *filename, int volume)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>playMusic</name>
      <anchorfile>da/d09/audio_8h.html</anchorfile>
      <anchor>a8fb0f93c63af671ba8a536f875f66f1d</anchor>
      <arglist>(const char *filename, int volume)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>playSoundFromMemory</name>
      <anchorfile>da/d09/audio_8h.html</anchorfile>
      <anchor>a5df7f8b69fad1f5fcd7ad6937f0c30cc</anchor>
      <arglist>(Audio *audio, int volume)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>playMusicFromMemory</name>
      <anchorfile>da/d09/audio_8h.html</anchorfile>
      <anchor>a95ded0954a20cfc7f3fb6ff68bb2452c</anchor>
      <arglist>(Audio *audio, int volume)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>endAudio</name>
      <anchorfile>da/d09/audio_8h.html</anchorfile>
      <anchor>a3fae9ccf354612f523af6a8078ae11d9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initAudio</name>
      <anchorfile>da/d09/audio_8h.html</anchorfile>
      <anchor>aa497dc0e932d8008a092680b6078ba0c</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>pauseAudio</name>
      <anchorfile>da/d09/audio_8h.html</anchorfile>
      <anchor>a80e7cce4d19baad74c85d0433e5920da</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unpauseAudio</name>
      <anchorfile>da/d09/audio_8h.html</anchorfile>
      <anchor>a59ae60979e26937b6934ebc4606307c9</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>combat.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>d9/dab/combat_8h.html</filename>
    <includes id="dd/da3/structures_8h" name="structures.h" local="yes" imported="no">structures.h</includes>
    <includes id="d9/d42/spells_8h" name="spells.h" local="yes" imported="no">spells.h</includes>
    <includes id="da/dab/inventory_8h" name="inventory.h" local="yes" imported="no">inventory.h</includes>
    <includes id="d8/da5/deplacement_8h" name="deplacement.h" local="yes" imported="no">deplacement.h</includes>
    <member kind="function">
      <type>perso_t</type>
      <name>init_player</name>
      <anchorfile>d9/dab/combat_8h.html</anchorfile>
      <anchor>a3790ce6458cef9238474baf44426c232</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init_monster</name>
      <anchorfile>d9/dab/combat_8h.html</anchorfile>
      <anchor>ae4af95d1a00a3eb23173ebac6a4b1387</anchor>
      <arglist>(monstre_t *monster, char *name, char *sprite, int hp, int dgt, int armor)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>aff_info</name>
      <anchorfile>d9/dab/combat_8h.html</anchorfile>
      <anchor>aeec6653f2b515dc92c85cb133ff8b8d2</anchor>
      <arglist>(perso_t *player, monstre_t *monstre, char *fond, char *sprite)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tour_joueur</name>
      <anchorfile>d9/dab/combat_8h.html</anchorfile>
      <anchor>a8217596f9d0ada09fc13341d48cc7122</anchor>
      <arglist>(perso_t *player, monstre_t *monstre)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tour_monstre</name>
      <anchorfile>d9/dab/combat_8h.html</anchorfile>
      <anchor>a6fda867fa46bf42bf625634bac4daeaf</anchor>
      <arglist>(perso_t *player, monstre_t *monstre)</arglist>
    </member>
    <member kind="function">
      <type>perso_t</type>
      <name>combat</name>
      <anchorfile>d9/dab/combat_8h.html</anchorfile>
      <anchor>aa2c1ca7f1bdf0a9c7e48a79c2890a095</anchor>
      <arglist>(perso_t *player, monstre_t *monstre)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>creation_map.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>d7/d00/creation__map_8h.html</filename>
    <includes id="d8/da5/deplacement_8h" name="deplacement.h" local="yes" imported="no">deplacement.h</includes>
    <member kind="function">
      <type>void</type>
      <name>lecture_fichier_map</name>
      <anchorfile>d7/d00/creation__map_8h.html</anchorfile>
      <anchor>ac9a48f18509215d355d5a91b3acfc19c</anchor>
      <arglist>(char nom_fichier[20], int map_int[Y][X])</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mise_struct_map</name>
      <anchorfile>d7/d00/creation__map_8h.html</anchorfile>
      <anchor>a0b794091f393311f6f4c3baf209d30c2</anchor>
      <arglist>(case_t map_info[Y][X], int map_int[Y][X])</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>afficher_map</name>
      <anchorfile>d7/d00/creation__map_8h.html</anchorfile>
      <anchor>a1fb91949070c5f69b74804a57cf94f17</anchor>
      <arglist>(char *nom_map, int taille, case_t map_info[Y][X])</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>deplacement.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>d8/da5/deplacement_8h.html</filename>
    <includes id="dd/da3/structures_8h" name="structures.h" local="yes" imported="no">structures.h</includes>
    <includes id="d2/dd5/game_8h" name="game.h" local="yes" imported="no">game.h</includes>
    <member kind="function">
      <type>void</type>
      <name>init_mat</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>a9c31d48445c5803a15c70851c22dcaf5</anchor>
      <arglist>(case_t mat[Y][X])</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>contour_mat</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>a7c700a504a0ea609fb3a5deb28c6b120</anchor>
      <arglist>(case_t mat[Y][X])</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>afficher_mat</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>a6e281bd852f3bc0b840baec39b3c8946</anchor>
      <arglist>(case_t mat[Y][X])</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>case_libre</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>a04260b3165d8fb41f19458afed0fd29b</anchor>
      <arglist>(case_t mat[Y][X], int coord_y, int coord_x)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>placer_pers</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>a47f25ac68281276f6abe6fcce529db3b</anchor>
      <arglist>(case_t mat[Y][X], int coord_y, int coord_x, perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>deplacer_pers</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>a89897777c3fd1de9394e6becb81d8dbe</anchor>
      <arglist>(case_t mat[Y][X], int coord_y, int coord_x, perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>gauche</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>a0622ec9dff683b30f2111e2f4aec8857</anchor>
      <arglist>(case_t mat[Y][X], perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>droite</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>a96bf9e7875cff5fa0ccbb1721731d6e6</anchor>
      <arglist>(case_t mat[Y][X], perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>dessus</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>a5bdbdc6208a68b49e5d3ab21c87ebbc1</anchor>
      <arglist>(case_t mat[Y][X], perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>dessous</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>a2d3825605142e376781f4535dc6aaa13</anchor>
      <arglist>(case_t mat[Y][X], perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>est_a_cote</name>
      <anchorfile>d8/da5/deplacement_8h.html</anchorfile>
      <anchor>ac07c3e82cdb4dce84ae9f0b758cf5089</anchor>
      <arglist>(case_t mat[Y][X], perso_t *perso)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fonction_sdl.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>d0/dea/fonction__sdl_8h.html</filename>
    <member kind="function">
      <type>void</type>
      <name>setcolor</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>af9bbd52e1fb3355ca65418d77f023b23</anchor>
      <arglist>(int, int)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>drawText</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>aebe6d58fb84ee534ca0427aa5a0b48f7</anchor>
      <arglist>(int, int, char *, int, int, SDL_Color)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>drawImage</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a71cbacd3612f3b99b170b894f2341e91</anchor>
      <arglist>(int, int, char *, int, int)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init_affichage</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a79d4020cf0b63c5c11c847b98348af97</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>loadImages</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a9a6c8918d7cb1e0eff8e5c574512da62</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unloadImages</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a1b8ec94d5f19922027d2c85ac4232398</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>showWindow</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>aae02cc4cef6bcbb0d78251146784b058</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fond_blanc</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>ac8372499b2cbfc9e82c12a3a003a426f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fond_rouge</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a42b50d6f3e8bb9a23498a642f94691f4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fond_vert</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a5455135b00eeef7d3eab7d3ec02269a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fond_bleu</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a6b9f30bd354d48d81d672c0214074fab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>faire_rendu</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a95c2e8cb34e25d1dd3f34153dc3512f2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>quitter_sdl</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a27bf92ff761d188ffc68b9232e78e76e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>quitter_affichage</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a9997b9c0deff4119dd1a312e048dd0b5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>afficher_image_menu</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>ac3b8549344c280045d9187e6c49bcba2</anchor>
      <arglist>(SDL_PRINTF_FORMAT_STRING char *nom)</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>SCREEN_HEIGHT</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>af1c710caf1e3a9e81829078054e83799</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>SCREEN_WIDTH</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a599adbe412c60e0cc5abb86be7ee4507</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>fenetre</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>aac3d10974df03ea537d2eb8ded2e17d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_Window *</type>
      <name>pWindow</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a41da1d9c960c28bf3d7e2ec2138425c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_Renderer *</type>
      <name>renderer</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a966da7a60c4ea3ba301e26ccc5efe452</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_Surface *</type>
      <name>image</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>aa73601f944838ffac2fa4d3e298a6ef4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_DisplayMode</type>
      <name>dm</name>
      <anchorfile>d0/dea/fonction__sdl_8h.html</anchorfile>
      <anchor>a9239b9be416490359dc85d089a239ada</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>game.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>d2/dd5/game_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>Y</name>
      <anchorfile>d2/dd5/game_8h.html</anchorfile>
      <anchor>a798e4073d613ca5ba9618e1b3253df14</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>X</name>
      <anchorfile>d2/dd5/game_8h.html</anchorfile>
      <anchor>a207fd5507206d307cd63f95374fcd00d</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>start</name>
      <anchorfile>d2/dd5/game_8h.html</anchorfile>
      <anchor>a60de64d75454385b23995437f1d72669</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>map</name>
      <anchorfile>d2/dd5/game_8h.html</anchorfile>
      <anchor>a39485a2726ea534ffb9f798fcaf1545d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lecture_fichier_map</name>
      <anchorfile>d2/dd5/game_8h.html</anchorfile>
      <anchor>ac9a48f18509215d355d5a91b3acfc19c</anchor>
      <arglist>(char nom_fichier[20], int map_int[Y][X])</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>gestion_deplacement_sdl.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>de/d3e/gestion__deplacement__sdl_8h.html</filename>
    <member kind="function">
      <type>int</type>
      <name>touche_detecter</name>
      <anchorfile>de/d3e/gestion__deplacement__sdl_8h.html</anchorfile>
      <anchor>a7b5d1496929e9a11c445f66cc3ac2062</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>SDL_Event</type>
      <name>events</name>
      <anchorfile>de/d3e/gestion__deplacement__sdl_8h.html</anchorfile>
      <anchor>a37f832e47591ca68e413d4718ea4f458</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>inventory.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>da/dab/inventory_8h.html</filename>
    <includes id="dd/da3/structures_8h" name="structures.h" local="yes" imported="no">structures.h</includes>
    <member kind="function">
      <type>int</type>
      <name>add_item</name>
      <anchorfile>da/dab/inventory_8h.html</anchorfile>
      <anchor>ab69ad73aa719fd7bb0d63a26f0a6734f</anchor>
      <arglist>(perso_t *player, int id, char *name, char *desc, int heal, int dgt, int armor)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>del_item</name>
      <anchorfile>da/dab/inventory_8h.html</anchorfile>
      <anchor>a157f10d450802cacb4be49cad09b2431</anchor>
      <arglist>(perso_t *player, int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>use_heal</name>
      <anchorfile>da/dab/inventory_8h.html</anchorfile>
      <anchor>a28b64e50a79cc64ac06e86949ea5aaed</anchor>
      <arglist>(perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>aff_inventory</name>
      <anchorfile>da/dab/inventory_8h.html</anchorfile>
      <anchor>a7bc318626fc83cfadadc28900d0f64f1</anchor>
      <arglist>(perso_t *player)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>menu_principal.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>d8/d8c/menu__principal_8h.html</filename>
    <member kind="function">
      <type>void</type>
      <name>Menu</name>
      <anchorfile>d8/d8c/menu__principal_8h.html</anchorfile>
      <anchor>afdf1ca9e7afc3e7ec41b47fea4b3d80d</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>spells.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>d9/d42/spells_8h.html</filename>
    <includes id="dd/da3/structures_8h" name="structures.h" local="yes" imported="no">structures.h</includes>
    <member kind="function">
      <type>void</type>
      <name>add_spell</name>
      <anchorfile>d9/d42/spells_8h.html</anchorfile>
      <anchor>ac406b871d394d9cc5cb14febd451da6f</anchor>
      <arglist>(perso_t *player, int num_spell, char *spell_name, int dgt)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>spell_existe</name>
      <anchorfile>d9/d42/spells_8h.html</anchorfile>
      <anchor>a9b7843c37f71e4b978bf75657fcee555</anchor>
      <arglist>(perso_t *player, int num_spell)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>spell_choice</name>
      <anchorfile>d9/d42/spells_8h.html</anchorfile>
      <anchor>ad9feb4a5045d784e03f30f355bd630a7</anchor>
      <arglist>(perso_t *player, int *spell_num)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>structures.h</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/lib/</path>
    <filename>dd/da3/structures_8h.html</filename>
    <class kind="struct">objet_s</class>
    <class kind="struct">case_s</class>
    <class kind="struct">perso_s</class>
    <class kind="struct">monstre_s</class>
    <class kind="struct">spell_s</class>
    <member kind="define">
      <type>#define</type>
      <name>NB_SPELLS</name>
      <anchorfile>dd/da3/structures_8h.html</anchorfile>
      <anchor>a05e290cec89058049106ec0564a04efd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAILLE_INV</name>
      <anchorfile>dd/da3/structures_8h.html</anchorfile>
      <anchor>ac29d7726f294f287d1794cf8cc828f6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>PLAYER_HP</name>
      <anchorfile>dd/da3/structures_8h.html</anchorfile>
      <anchor>ab79bf1ced3b25083a255fb0748b0b31c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>affichage_sdl.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>da/d78/affichage__sdl_8c.html</filename>
    <includes id="d8/d1b/affichage__sdl_8h" name="affichage_sdl.h" local="yes" imported="no">../lib/affichage_sdl.h</includes>
    <includes id="d0/dea/fonction__sdl_8h" name="fonction_sdl.h" local="yes" imported="no">../lib/fonction_sdl.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>TAILLE_MAX</name>
      <anchorfile>da/d78/affichage__sdl_8c.html</anchorfile>
      <anchor>ae6ad0540d5109a0200f0dde5dc5b4bf6</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>afficher_menu</name>
      <anchorfile>da/d78/affichage__sdl_8c.html</anchorfile>
      <anchor>a0a86720440ed48cd84f9bda8b7ca10f6</anchor>
      <arglist>(char menu[4][30])</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>affichage_dialogue</name>
      <anchorfile>da/d78/affichage__sdl_8c.html</anchorfile>
      <anchor>a38dc84bd7da8d9d381981d966f4c7b8d</anchor>
      <arglist>(char *id_PNJ)</arglist>
    </member>
    <member kind="variable">
      <type>TTF_Font *</type>
      <name>police</name>
      <anchorfile>da/d78/affichage__sdl_8c.html</anchorfile>
      <anchor>a49a11b0728728090fa1189391c9fe0c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_Color</type>
      <name>jaune</name>
      <anchorfile>da/d78/affichage__sdl_8c.html</anchorfile>
      <anchor>a7368b709b22538a39462fd37ea1a2151</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_Color</type>
      <name>noire</name>
      <anchorfile>da/d78/affichage__sdl_8c.html</anchorfile>
      <anchor>a7b1e239da7325a1f77d284b1ac12a701</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>audio.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>d3/d9a/audio_8c.html</filename>
    <includes id="da/d09/audio_8h" name="audio.h" local="yes" imported="no">../lib/audio.h</includes>
    <class kind="struct">PrivateAudioDevice</class>
    <member kind="define">
      <type>#define</type>
      <name>AUDIO_FORMAT</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a25ef1d957093181c04182f3c55f3f1ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>AUDIO_FREQUENCY</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>aae969438a57a86fddf0cf53106c9b6b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>AUDIO_CHANNELS</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a8fc745a0f6e356f4b79cb0ab059c40f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>AUDIO_SAMPLES</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a58e80361cf95d18afbe8f25713f4cdc6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>AUDIO_MAX_SOUNDS</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a745ce39b149e95ee75d50b9c99578469</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>AUDIO_MUSIC_FADE_VALUE</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>ac38de408d890f92223100b5b1e1aa809</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SDL_AUDIO_ALLOW_CHANGES</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a0398585ffb30b83b6686b78e61317d1d</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>addMusic</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>ab4172bac28cebfdba5ec4bcd3b0cb390</anchor>
      <arglist>(Audio *root, Audio *newAudio)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>playAudio</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a7a8c2c1a553b4eb15711bccc4e950199</anchor>
      <arglist>(const char *filename, Audio *audio, uint8_t loop, int volume)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>addAudio</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a31815ea21df258dbe2e50db77380cf08</anchor>
      <arglist>(Audio *root, Audio *newAudio)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>audioCallback</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a4d77eb648242c09f939373f6fc5aa1a3</anchor>
      <arglist>(void *userdata, uint8_t *stream, int len)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>playSound</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>aa2a1c236a8c22740fd92902a1929f36d</anchor>
      <arglist>(const char *filename, int volume)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>playMusic</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a8fb0f93c63af671ba8a536f875f66f1d</anchor>
      <arglist>(const char *filename, int volume)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>playSoundFromMemory</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a5df7f8b69fad1f5fcd7ad6937f0c30cc</anchor>
      <arglist>(Audio *audio, int volume)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>playMusicFromMemory</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a95ded0954a20cfc7f3fb6ff68bb2452c</anchor>
      <arglist>(Audio *audio, int volume)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initAudio</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>aa497dc0e932d8008a092680b6078ba0c</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>endAudio</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a3fae9ccf354612f523af6a8078ae11d9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>pauseAudio</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a80e7cce4d19baad74c85d0433e5920da</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unpauseAudio</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a59ae60979e26937b6934ebc4606307c9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>freeAudio</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>aa3730ab77fa3498af628a47bbe29fac0</anchor>
      <arglist>(Audio *audio)</arglist>
    </member>
    <member kind="function">
      <type>Audio *</type>
      <name>createAudio</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>a83eb6efb3d674325c1377daf30c54883</anchor>
      <arglist>(const char *filename, uint8_t loop, int volume)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static PrivateAudioDevice *</type>
      <name>gDevice</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>af9ea75dd614f75c35ec73935e0fcf3e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static uint32_t</type>
      <name>gSoundCount</name>
      <anchorfile>d3/d9a/audio_8c.html</anchorfile>
      <anchor>aead5b624b88785e5df99ee5e9a552289</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>combat.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>d3/d19/combat_8c.html</filename>
    <includes id="d0/dea/fonction__sdl_8h" name="fonction_sdl.h" local="yes" imported="no">../lib/fonction_sdl.h</includes>
    <includes id="d9/dab/combat_8h" name="combat.h" local="yes" imported="no">../lib/combat.h</includes>
    <includes id="da/d09/audio_8h" name="audio.h" local="yes" imported="no">../lib/audio.h</includes>
    <member kind="function">
      <type>int</type>
      <name>__itoa</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>a96205f2a14e4cbb7bb7dd3430301c5a0</anchor>
      <arglist>(int num, char *result, int base, int nbrNum)</arglist>
    </member>
    <member kind="function">
      <type>perso_t</type>
      <name>init_player</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>a3790ce6458cef9238474baf44426c232</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init_monster</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>ae4af95d1a00a3eb23173ebac6a4b1387</anchor>
      <arglist>(monstre_t *monster, char *name, char *sprite, int hp, int dgt, int armor)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>aff_info</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>aeec6653f2b515dc92c85cb133ff8b8d2</anchor>
      <arglist>(perso_t *player, monstre_t *monstre, char *fond, char *sprite)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tour_joueur</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>a8217596f9d0ada09fc13341d48cc7122</anchor>
      <arglist>(perso_t *player, monstre_t *monstre)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tour_monstre</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>a6fda867fa46bf42bf625634bac4daeaf</anchor>
      <arglist>(perso_t *player, monstre_t *monstre)</arglist>
    </member>
    <member kind="function">
      <type>perso_t</type>
      <name>combat</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>aa2c1ca7f1bdf0a9c7e48a79c2890a095</anchor>
      <arglist>(perso_t *player, monstre_t *monstre)</arglist>
    </member>
    <member kind="variable">
      <type>SDL_Color</type>
      <name>noir</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>af56a332369e584ec6bd865caafde6968</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_Color</type>
      <name>rouge</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>ae518f700a693af4946e6cf7ca4526ca0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_Color</type>
      <name>blanc</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>ace66e6bb8b731a6aa0d43bcf61d638cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>hp_joueur</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>af878fe4c9f532e91d2a1a533bab980ea</anchor>
      <arglist>[3]</arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>hp_monstre</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>ae6fc5b48df812dab2e3fd980b561a5f5</anchor>
      <arglist>[3]</arglist>
    </member>
    <member kind="variable">
      <type>char</type>
      <name>inf_dgt</name>
      <anchorfile>d3/d19/combat_8c.html</anchorfile>
      <anchor>a0b3edbdb6a7fc8a0d1c8f65dccb3ce20</anchor>
      <arglist>[2]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>creation_map.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>dd/d49/creation__map_8c.html</filename>
    <includes id="d8/da5/deplacement_8h" name="deplacement.h" local="yes" imported="no">../lib/deplacement.h</includes>
    <includes id="d7/d00/creation__map_8h" name="creation_map.h" local="yes" imported="no">../lib/creation_map.h</includes>
    <includes id="d0/dea/fonction__sdl_8h" name="fonction_sdl.h" local="yes" imported="no">../lib/fonction_sdl.h</includes>
    <member kind="function">
      <type>float</type>
      <name>time_diff2</name>
      <anchorfile>dd/d49/creation__map_8c.html</anchorfile>
      <anchor>aebc73c654d4e16f68bee16dcc0954e78</anchor>
      <arglist>(struct timespec *start, struct timespec *end)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lecture_fichier_map</name>
      <anchorfile>dd/d49/creation__map_8c.html</anchorfile>
      <anchor>ac9a48f18509215d355d5a91b3acfc19c</anchor>
      <arglist>(char nom_fichier[20], int map_int[Y][X])</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mise_struct_map</name>
      <anchorfile>dd/d49/creation__map_8c.html</anchorfile>
      <anchor>a0b794091f393311f6f4c3baf209d30c2</anchor>
      <arglist>(case_t map_info[Y][X], int map_int[Y][X])</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>afficher_map</name>
      <anchorfile>dd/d49/creation__map_8c.html</anchorfile>
      <anchor>a1fb91949070c5f69b74804a57cf94f17</anchor>
      <arglist>(char *nom_map, int taille, case_t map_info[Y][X])</arglist>
    </member>
    <member kind="variable">
      <type>case_t</type>
      <name>map_info</name>
      <anchorfile>dd/d49/creation__map_8c.html</anchorfile>
      <anchor>a7ecc9794dfc2a2ed2910bc99641f6ad6</anchor>
      <arglist>[Y][X]</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>map_int</name>
      <anchorfile>dd/d49/creation__map_8c.html</anchorfile>
      <anchor>acf9110daf854663f7d833211cfec828e</anchor>
      <arglist>[Y][X]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>deplacement.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>d7/d05/deplacement_8c.html</filename>
    <includes id="d8/da5/deplacement_8h" name="deplacement.h" local="yes" imported="no">../lib/deplacement.h</includes>
    <member kind="function">
      <type>void</type>
      <name>init_mat</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>a9c31d48445c5803a15c70851c22dcaf5</anchor>
      <arglist>(case_t mat[Y][X])</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>contour_mat</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>a7c700a504a0ea609fb3a5deb28c6b120</anchor>
      <arglist>(case_t mat[Y][X])</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>afficher_mat</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>a6e281bd852f3bc0b840baec39b3c8946</anchor>
      <arglist>(case_t mat[Y][X])</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>case_libre</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>a04260b3165d8fb41f19458afed0fd29b</anchor>
      <arglist>(case_t mat[Y][X], int coord_y, int coord_x)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>placer_pers</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>a47f25ac68281276f6abe6fcce529db3b</anchor>
      <arglist>(case_t mat[Y][X], int coord_y, int coord_x, perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>deplacer_pers</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>a89897777c3fd1de9394e6becb81d8dbe</anchor>
      <arglist>(case_t mat[Y][X], int coord_y, int coord_x, perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>gauche</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>a0622ec9dff683b30f2111e2f4aec8857</anchor>
      <arglist>(case_t mat[Y][X], perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>droite</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>a96bf9e7875cff5fa0ccbb1721731d6e6</anchor>
      <arglist>(case_t mat[Y][X], perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>dessus</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>a5bdbdc6208a68b49e5d3ab21c87ebbc1</anchor>
      <arglist>(case_t mat[Y][X], perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>dessous</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>a2d3825605142e376781f4535dc6aaa13</anchor>
      <arglist>(case_t mat[Y][X], perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>est_a_cote</name>
      <anchorfile>d7/d05/deplacement_8c.html</anchorfile>
      <anchor>ac07c3e82cdb4dce84ae9f0b758cf5089</anchor>
      <arglist>(case_t mat[Y][X], perso_t *perso)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fonction_sdl.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>d9/da1/fonction__sdl_8c.html</filename>
    <includes id="d0/dea/fonction__sdl_8h" name="fonction_sdl.h" local="yes" imported="no">../lib/fonction_sdl.h</includes>
    <member kind="function">
      <type>void</type>
      <name>loadImages</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a9a6c8918d7cb1e0eff8e5c574512da62</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unloadImages</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a1b8ec94d5f19922027d2c85ac4232398</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>faire_rendu</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a95c2e8cb34e25d1dd3f34153dc3512f2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fond_blanc</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>ac8372499b2cbfc9e82c12a3a003a426f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fond_rouge</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a42b50d6f3e8bb9a23498a642f94691f4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fond_vert</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a5455135b00eeef7d3eab7d3ec02269a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fond_bleu</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a6b9f30bd354d48d81d672c0214074fab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>quitter_affichage</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a9997b9c0deff4119dd1a312e048dd0b5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>drawText</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a55ed689bac95823b56801c705ab8496e</anchor>
      <arglist>(int x, int y, char *string, int h, int w, SDL_Color color)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>drawImage</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>adbbccbf07482575ee093f705dc02108a</anchor>
      <arglist>(int x, int y, char *nom, int w, int h)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init_affichage</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a79d4020cf0b63c5c11c847b98348af97</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>afficher_image_menu</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a9dc3d841a878f31da123d3a5167bd6f1</anchor>
      <arglist>(SDL_PRINTF_FORMAT_STRING char *nom)</arglist>
    </member>
    <member kind="variable">
      <type>SDL_Renderer *</type>
      <name>renderer</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a966da7a60c4ea3ba301e26ccc5efe452</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_Texture *</type>
      <name>images</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a4df1f7d8e3653290ac077584b73fd2d1</anchor>
      <arglist>[300]</arglist>
    </member>
    <member kind="variable">
      <type>TTF_Font *</type>
      <name>police</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a49a11b0728728090fa1189391c9fe0c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>nb_images</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>ae2e41bb3a59a2d21905a767a95c010f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char **</type>
      <name>noms</name>
      <anchorfile>d9/da1/fonction__sdl_8c.html</anchorfile>
      <anchor>a74fe753395adaf30b4184a08a232d7bc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>game.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>d1/dcb/game_8c.html</filename>
    <includes id="d0/dea/fonction__sdl_8h" name="fonction_sdl.h" local="yes" imported="no">../lib/fonction_sdl.h</includes>
    <includes id="de/d3e/gestion__deplacement__sdl_8h" name="gestion_deplacement_sdl.h" local="yes" imported="no">../lib/gestion_deplacement_sdl.h</includes>
    <includes id="d8/d8c/menu__principal_8h" name="menu_principal.h" local="yes" imported="no">../lib/menu_principal.h</includes>
    <includes id="d8/da5/deplacement_8h" name="deplacement.h" local="yes" imported="no">../lib/deplacement.h</includes>
    <includes id="d8/d1b/affichage__sdl_8h" name="affichage_sdl.h" local="yes" imported="no">../lib/affichage_sdl.h</includes>
    <includes id="d2/dd5/game_8h" name="game.h" local="yes" imported="no">../lib/game.h</includes>
    <includes id="d7/d00/creation__map_8h" name="creation_map.h" local="yes" imported="no">../lib/creation_map.h</includes>
    <includes id="d9/dab/combat_8h" name="combat.h" local="yes" imported="no">../lib/combat.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>TAILLE_CASE_PXL</name>
      <anchorfile>d1/dcb/game_8c.html</anchorfile>
      <anchor>a2c41b5564334ffcdbfcd4ab68211aa54</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DROP_RATE</name>
      <anchorfile>d1/dcb/game_8c.html</anchorfile>
      <anchor>a0afb51fa0576fe48f6f825db1acd0f66</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>info_case</name>
      <anchorfile>d1/dcb/game_8c.html</anchorfile>
      <anchor>aa6d96ab6476527b240917c534678608e</anchor>
      <arglist>(case_t mat[Y][X], int coord_y, int coord_x)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sauvegarder_jeu</name>
      <anchorfile>d1/dcb/game_8c.html</anchorfile>
      <anchor>a13a49ef169ef1f0ec87271a48d36e0fc</anchor>
      <arglist>(case_t mat[Y][X], perso_t *perso, char *nom_map)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>interaction_pnj</name>
      <anchorfile>d1/dcb/game_8c.html</anchorfile>
      <anchor>aa0faf4e3e17cb4141a36f3ab94cb7960</anchor>
      <arglist>(case_t mat[Y][X], perso_t *perso)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>start</name>
      <anchorfile>d1/dcb/game_8c.html</anchorfile>
      <anchor>a60de64d75454385b23995437f1d72669</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>char *</type>
      <name>nom_map</name>
      <anchorfile>d1/dcb/game_8c.html</anchorfile>
      <anchor>a6d28848978f6a6ff67bb4db2bc7341ae</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>gestion_deplacement_sdl.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>de/d62/gestion__deplacement__sdl_8c.html</filename>
    <includes id="de/d3e/gestion__deplacement__sdl_8h" name="gestion_deplacement_sdl.h" local="yes" imported="no">../lib/gestion_deplacement_sdl.h</includes>
    <includes id="d0/dea/fonction__sdl_8h" name="fonction_sdl.h" local="yes" imported="no">../lib/fonction_sdl.h</includes>
    <member kind="function">
      <type>int</type>
      <name>touche_detecter</name>
      <anchorfile>de/d62/gestion__deplacement__sdl_8c.html</anchorfile>
      <anchor>a7b5d1496929e9a11c445f66cc3ac2062</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>SDL_Event</type>
      <name>event</name>
      <anchorfile>de/d62/gestion__deplacement__sdl_8c.html</anchorfile>
      <anchor>a6b57f01d3c576db5368dd0efc2f435a4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>inventory.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>de/d04/inventory_8c.html</filename>
    <includes id="da/dab/inventory_8h" name="inventory.h" local="yes" imported="no">../lib/inventory.h</includes>
    <member kind="function">
      <type>int</type>
      <name>add_item</name>
      <anchorfile>de/d04/inventory_8c.html</anchorfile>
      <anchor>a615ed55f7d61fc26f639449ba4f1199d</anchor>
      <arglist>(perso_t *player, int id, char *name, char *desc, int heal, int dgt, int armor)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>del_item</name>
      <anchorfile>de/d04/inventory_8c.html</anchorfile>
      <anchor>a157f10d450802cacb4be49cad09b2431</anchor>
      <arglist>(perso_t *player, int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>use_heal</name>
      <anchorfile>de/d04/inventory_8c.html</anchorfile>
      <anchor>a28b64e50a79cc64ac06e86949ea5aaed</anchor>
      <arglist>(perso_t *player)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>aff_inventory</name>
      <anchorfile>de/d04/inventory_8c.html</anchorfile>
      <anchor>a7bc318626fc83cfadadc28900d0f64f1</anchor>
      <arglist>(perso_t *player)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>main.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>d0/d29/main_8c.html</filename>
    <includes id="d8/d8c/menu__principal_8h" name="menu_principal.h" local="yes" imported="no">../lib/menu_principal.h</includes>
    <includes id="d0/dea/fonction__sdl_8h" name="fonction_sdl.h" local="yes" imported="no">../lib/fonction_sdl.h</includes>
    <includes id="d8/da5/deplacement_8h" name="deplacement.h" local="yes" imported="no">../lib/deplacement.h</includes>
    <member kind="function">
      <type>int</type>
      <name>main</name>
      <anchorfile>d0/d29/main_8c.html</anchorfile>
      <anchor>a3c04138a5bfe5d72780bb7e82a18e627</anchor>
      <arglist>(int argc, char **argv)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>menu_principal.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>df/d1b/menu__principal_8c.html</filename>
    <includes id="d8/d1b/affichage__sdl_8h" name="affichage_sdl.h" local="yes" imported="no">../lib/affichage_sdl.h</includes>
    <includes id="d0/dea/fonction__sdl_8h" name="fonction_sdl.h" local="yes" imported="no">../lib/fonction_sdl.h</includes>
    <includes id="d2/dd5/game_8h" name="game.h" local="yes" imported="no">../lib/game.h</includes>
    <member kind="function">
      <type>void</type>
      <name>Menu</name>
      <anchorfile>df/d1b/menu__principal_8c.html</anchorfile>
      <anchor>afdf1ca9e7afc3e7ec41b47fea4b3d80d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>TTF_Font *</type>
      <name>police</name>
      <anchorfile>df/d1b/menu__principal_8c.html</anchorfile>
      <anchor>a49a11b0728728090fa1189391c9fe0c8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>spells.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>d2/d8d/spells_8c.html</filename>
    <includes id="d9/d42/spells_8h" name="spells.h" local="yes" imported="no">../lib/spells.h</includes>
    <member kind="function">
      <type>void</type>
      <name>add_spell</name>
      <anchorfile>d2/d8d/spells_8c.html</anchorfile>
      <anchor>ac406b871d394d9cc5cb14febd451da6f</anchor>
      <arglist>(perso_t *player, int num_spell, char *spell_name, int dgt)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>spell_existe</name>
      <anchorfile>d2/d8d/spells_8c.html</anchorfile>
      <anchor>a9b7843c37f71e4b978bf75657fcee555</anchor>
      <arglist>(perso_t *player, int num_spell)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>spell_choice</name>
      <anchorfile>d2/d8d/spells_8c.html</anchorfile>
      <anchor>ad9feb4a5045d784e03f30f355bd630a7</anchor>
      <arglist>(perso_t *player, int *spell_num)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>test_deplacement.c</name>
    <path>/info/etu/l2info/s202278/Wolfpine/Wolfpine-RPG/src/</path>
    <filename>d5/d47/test__deplacement_8c.html</filename>
    <includes id="d9/dab/combat_8h" name="combat.h" local="yes" imported="no">../lib/combat.h</includes>
    <member kind="function">
      <type>int</type>
      <name>main</name>
      <anchorfile>d5/d47/test__deplacement_8c.html</anchorfile>
      <anchor>ae66f6b31b5ad750f1fe042a706a4e3d4</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Audio</name>
    <filename>dc/d69/struct_audio.html</filename>
    <member kind="variable">
      <type>uint32_t</type>
      <name>length</name>
      <anchorfile>dc/d69/struct_audio.html</anchorfile>
      <anchor>a7e8c9a5ca37dc868542902b8328deaad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint32_t</type>
      <name>lengthTrue</name>
      <anchorfile>dc/d69/struct_audio.html</anchorfile>
      <anchor>a2fa8d2a2d4c6e83d37f36a0026830d4d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint8_t *</type>
      <name>bufferTrue</name>
      <anchorfile>dc/d69/struct_audio.html</anchorfile>
      <anchor>a13b38888ff854f5587a9ce25aea417d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint8_t *</type>
      <name>buffer</name>
      <anchorfile>dc/d69/struct_audio.html</anchorfile>
      <anchor>a491b84a20d7ccb9b52dee4357c7dae15</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint8_t</type>
      <name>loop</name>
      <anchorfile>dc/d69/struct_audio.html</anchorfile>
      <anchor>a9b3d4a3e789e1688cc91666ac94cff4d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint8_t</type>
      <name>fade</name>
      <anchorfile>dc/d69/struct_audio.html</anchorfile>
      <anchor>abb3611172d2af3f8cd67d6f2e259ec86</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint8_t</type>
      <name>free</name>
      <anchorfile>dc/d69/struct_audio.html</anchorfile>
      <anchor>a5fb59d5671325dd2460ce1b613dc4555</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint8_t</type>
      <name>volume</name>
      <anchorfile>dc/d69/struct_audio.html</anchorfile>
      <anchor>aff309cb275657927818ce381e5222285</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_AudioSpec</type>
      <name>audio</name>
      <anchorfile>dc/d69/struct_audio.html</anchorfile>
      <anchor>a434856de9dbf4b4bf2c1173a3db9fc9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct sound *</type>
      <name>next</name>
      <anchorfile>dc/d69/struct_audio.html</anchorfile>
      <anchor>a58920d11420b003844e9b21493a88272</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>case_s</name>
    <filename>d3/d6b/structcase__s.html</filename>
    <member kind="variable">
      <type>char *</type>
      <name>id</name>
      <anchorfile>d3/d6b/structcase__s.html</anchorfile>
      <anchor>aa3347173d1a477fb824d36a1b15b0579</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>col</name>
      <anchorfile>d3/d6b/structcase__s.html</anchorfile>
      <anchor>aa5a1f92b3730b8086077f1fc2560ce3f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>case_t</name>
    <filename>d9/d08/structcase__t.html</filename>
  </compound>
  <compound kind="struct">
    <name>monstre_s</name>
    <filename>d7/d08/structmonstre__s.html</filename>
    <member kind="variable">
      <type>char *</type>
      <name>name</name>
      <anchorfile>d7/d08/structmonstre__s.html</anchorfile>
      <anchor>a8fffe49195dabfef6fc3af6ca8ce4dbe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char *</type>
      <name>sprite</name>
      <anchorfile>d7/d08/structmonstre__s.html</anchorfile>
      <anchor>a3c1f4d19bcf27d3c3f4b4351ef2e0a34</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>hp</name>
      <anchorfile>d7/d08/structmonstre__s.html</anchorfile>
      <anchor>a17e3fecd10d4df836572440c37afc959</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>dgt</name>
      <anchorfile>d7/d08/structmonstre__s.html</anchorfile>
      <anchor>aac77db775d86c6c3df090dfeb2cc3770</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>armor</name>
      <anchorfile>d7/d08/structmonstre__s.html</anchorfile>
      <anchor>ad011745a19b2d25681269a717fb3f5b2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>monstre_t</name>
    <filename>d4/ddf/structmonstre__t.html</filename>
  </compound>
  <compound kind="struct">
    <name>objet_s</name>
    <filename>da/d7d/structobjet__s.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>id</name>
      <anchorfile>da/d7d/structobjet__s.html</anchorfile>
      <anchor>a535563dd45e5162e57e544a87b888de1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>qte</name>
      <anchorfile>da/d7d/structobjet__s.html</anchorfile>
      <anchor>a09761f5cd4b2f93dfbc6fc32bfa6da1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char *</type>
      <name>name</name>
      <anchorfile>da/d7d/structobjet__s.html</anchorfile>
      <anchor>a56713ecec7464e9807ae0fc1db83ce8c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char *</type>
      <name>desc</name>
      <anchorfile>da/d7d/structobjet__s.html</anchorfile>
      <anchor>aac59d0a9f9cf4cf9279245fc3f0f0b08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>heal</name>
      <anchorfile>da/d7d/structobjet__s.html</anchorfile>
      <anchor>a124a9e172e579adafd2aacf0ef0cba90</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>dgt</name>
      <anchorfile>da/d7d/structobjet__s.html</anchorfile>
      <anchor>a318efcd3c6fccee40c6742384ebb652b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>armor</name>
      <anchorfile>da/d7d/structobjet__s.html</anchorfile>
      <anchor>abace21a28d1d0ddb4c13f4650a79ff03</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>objet_t</name>
    <filename>d6/d8d/structobjet__t.html</filename>
  </compound>
  <compound kind="struct">
    <name>perso_s</name>
    <filename>de/d7a/structperso__s.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>anc_coord_x</name>
      <anchorfile>de/d7a/structperso__s.html</anchorfile>
      <anchor>a1fa61f0e1122b2840601b4d8ab358ca2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>anc_coord_y</name>
      <anchorfile>de/d7a/structperso__s.html</anchorfile>
      <anchor>afcd517deeb15668438a5ebe8e41a4e7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char *</type>
      <name>position</name>
      <anchorfile>de/d7a/structperso__s.html</anchorfile>
      <anchor>ac8a032bef1c9edd16e59f9b0ace98485</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char *</type>
      <name>name</name>
      <anchorfile>de/d7a/structperso__s.html</anchorfile>
      <anchor>acc0fc99fe730ed951e3c82c646dc8c95</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>hp</name>
      <anchorfile>de/d7a/structperso__s.html</anchorfile>
      <anchor>a561b96b38c31a97e3b41c4aa7a8ed5f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>dgt</name>
      <anchorfile>de/d7a/structperso__s.html</anchorfile>
      <anchor>a87b3245885fafa3dbee35981f1514dfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>armor</name>
      <anchorfile>de/d7a/structperso__s.html</anchorfile>
      <anchor>abdde7b5dfd139e2bf3e01cf368aaaebf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>spell_t *</type>
      <name>spell</name>
      <anchorfile>de/d7a/structperso__s.html</anchorfile>
      <anchor>a3b10ee4feaf854b3b56a2954edcd1450</anchor>
      <arglist>[NB_SPELLS]</arglist>
    </member>
    <member kind="variable">
      <type>objet_t *</type>
      <name>objets</name>
      <anchorfile>de/d7a/structperso__s.html</anchorfile>
      <anchor>af23a5aed5a57756cca4afa940b262e0c</anchor>
      <arglist>[TAILLE_INV]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>perso_t</name>
    <filename>df/de6/structperso__t.html</filename>
  </compound>
  <compound kind="struct">
    <name>PrivateAudioDevice</name>
    <filename>d2/dcc/struct_private_audio_device.html</filename>
    <member kind="variable">
      <type>SDL_AudioDeviceID</type>
      <name>device</name>
      <anchorfile>d2/dcc/struct_private_audio_device.html</anchorfile>
      <anchor>ae0ef52cc14c68199540c718d893bd8bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SDL_AudioSpec</type>
      <name>want</name>
      <anchorfile>d2/dcc/struct_private_audio_device.html</anchorfile>
      <anchor>a4be64dd1a91a9931c5a83dd8ead550cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint8_t</type>
      <name>audioEnabled</name>
      <anchorfile>d2/dcc/struct_private_audio_device.html</anchorfile>
      <anchor>a59f47a0ebc5e3a1e46320fd2986a80ba</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>spell_s</name>
    <filename>d2/d28/structspell__s.html</filename>
    <member kind="variable">
      <type>char *</type>
      <name>name</name>
      <anchorfile>d2/d28/structspell__s.html</anchorfile>
      <anchor>a37ddf1a3081881c5ec98b43a98be3d39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>dgt</name>
      <anchorfile>d2/d28/structspell__s.html</anchorfile>
      <anchor>a03986fe4fff25cfc8e3e147859549693</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>spell_t</name>
    <filename>da/d9f/structspell__t.html</filename>
  </compound>
</tagfile>
