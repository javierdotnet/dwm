//
// Created by javier on 24/7/20.
//

#ifndef DWM_LUKESMITH_RULES_H
#define DWM_LUKESMITH_RULES_H

static const Rule rules[] = {
        /* xprop(1):
         *	WM_CLASS(STRING) = instance, class
         *	WM_NAME(STRING) = title
        */
        /* class    instance      title       	 tags mask    iscentered  isfloating   isterminal  noswallow  monitor */
        {"Gimp", NULL, NULL, 1 << 8, 0, 0, 0, 0, -1},
        {"Glimpse", NULL, NULL, 1 << 8, 0, 0, 0, 0, -1},

        {"joplin", NULL, NULL, 1 << 2, 0, 0, 0, 0, -1},
        {"Joplin", NULL, NULL, 1 << 2, 0, 0, 0, 0, -1},

        {"firefoxdeveloperedition", NULL, NULL, 2, 0, 0, 0, 0, -1},
        {"Navigator", NULL, NULL, 2, 0,  0, 0, 0, -1},

        {"brave-browser", NULL, NULL, 2, 1, 0, 0, 0, -1},
        {"Brave-browser", NULL, NULL, 2, 1, 0, 0, 0, -1},

        {"chromium", NULL, NULL, 1 << 3, 1, 0, 0, 0, -1},
        {"Chromium", NULL, NULL, 1 << 3, 1, 0, 0, 0, -1},


        {"jetbrains-idea", NULL, NULL, 1 << 7, 1, 0, 0, 0, -1},
        {"jetbrains-clion", NULL, NULL, 1 << 5  , 1, 0, 0, 0, -1},
        {"jetbrains-phpstorm", NULL, NULL, 1 << 6  , 1, 0, 0, 0, -1},
        {"Eclipse", NULL, NULL, 1 << 7  , 1, 0, 0, 0, -1},


        {"subl3", NULL, NULL, 1 << 3, 0, 0, 0, 0, -1},
        {"Subl3", NULL, NULL, 1 << 3, 0, 0, 0, 0, -1},
        {"VNC Viewer", NULL, NULL, 1 << 7, 1, 0, 0, 0, -1},
        {"realvnc-vncviewer", NULL, NULL, 1 << 8, 1, 0, 0, 0, -1},

        {"vscodium", NULL, NULL, 1 << 3, 0, 0, 0, 0, -1},
        {"VSCodium", NULL, NULL, 1 << 3, 0, 0, 0, 0, -1},

        {"urxvt", NULL, NULL, 0, 1 , 0, 1, 0, -1},
        {NULL, NULL, "Event Tester", 0, 0, 0, 0, 1, -1},
        {NULL, "spterm", NULL, SPTAG(0), 1, 1, 0, -1},
        {NULL, "spcalc", NULL, SPTAG(1), 1, 1, 0, -1},

        {"copyq", NULL, NULL, 0, 1, 1 , 0, 0, -1},

        {"orage", NULL, NULL, 1, 1, 0, 0, -1},
        {"Orage", NULL, NULL, 1, 1, 0, 0, -1},


};

#endif //DWM_LUKESMITH_RULES_H
