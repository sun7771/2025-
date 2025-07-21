/*
 * Copyright 2025 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"

extern float humi, temp;
extern float filtered_roll, filtered_pitch, filtered_yaw;

void screen_2_update_labels2(lv_timer_t *timer)
{
    lv_ui *ui = (lv_ui *)timer->user_data;
    char buf[32];

    sprintf(buf, "Pitch:%.1f", filtered_roll);
    lv_label_set_text(ui->screen_2_label_4, buf);

    sprintf(buf, "Roll:%.1f", filtered_pitch);
    lv_label_set_text(ui->screen_2_label_5, buf);

    sprintf(buf, "Yaw:%.1f", filtered_yaw);
    lv_label_set_text(ui->screen_2_label_6, buf);
}

void screen_2_update_labels1(lv_timer_t *timer)
{
    lv_ui *ui = (lv_ui *)timer->user_data;
    char buf[32];

    sprintf(buf, "温度：%.1f", temp);
    lv_label_set_text(ui->screen_2_label_2, buf);

    sprintf(buf, "湿度：%.0f%%", humi);
    lv_label_set_text(ui->screen_2_label_3, buf);
}

void setup_scr_screen_2(lv_ui *ui)
{
    // Write codes screen_2
    ui->screen_2 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_2, 320, 240);
    lv_obj_set_scrollbar_mode(ui->screen_2, LV_SCROLLBAR_MODE_OFF);

    // Write style for screen_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_2_label_1
    ui->screen_2_label_1 = lv_label_create(ui->screen_2);
    lv_label_set_text(ui->screen_2_label_1, "传感器\n");
    lv_label_set_long_mode(ui->screen_2_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_1, 110, 13);
    lv_obj_set_size(ui->screen_2_label_1, 100, 32);

    // Write style for screen_2_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_1, &lv_font_SourceHanSansCN_Normal_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_2_label_2
    ui->screen_2_label_2 = lv_label_create(ui->screen_2);

    lv_label_set_text(ui->screen_2_label_2, "温度：");
    lv_label_set_long_mode(ui->screen_2_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_2, 24, 45);
    lv_obj_set_size(ui->screen_2_label_2, 100, 32);

    // Write style for screen_2_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_2, &lv_font_SourceHanSansCN_Normal_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_2_label_3
    ui->screen_2_label_3 = lv_label_create(ui->screen_2);
    lv_label_set_text(ui->screen_2_label_3, "湿度：");
    lv_label_set_long_mode(ui->screen_2_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_3, 24, 77);
    lv_obj_set_size(ui->screen_2_label_3, 100, 32);

    // Write style for screen_2_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_3, &lv_font_SourceHanSansCN_Normal_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_2_label_4
    ui->screen_2_label_4 = lv_label_create(ui->screen_2);
    lv_label_set_text(ui->screen_2_label_4, "Pitch：");
    lv_label_set_long_mode(ui->screen_2_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_4, 24, 105);
    lv_obj_set_size(ui->screen_2_label_4, 100, 32);

    // Write style for screen_2_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_4, &lv_font_SourceHanSansCN_Normal_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_2_label_5
    ui->screen_2_label_5 = lv_label_create(ui->screen_2);
    lv_label_set_text(ui->screen_2_label_5, "Roll:");
    lv_label_set_long_mode(ui->screen_2_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_5, 18, 137);
    lv_obj_set_size(ui->screen_2_label_5, 100, 32);

    // Write style for screen_2_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_5, &lv_font_SourceHanSansCN_Normal_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_2_label_6
    ui->screen_2_label_6 = lv_label_create(ui->screen_2);
    lv_label_set_text(ui->screen_2_label_6, "Yaw:");
    lv_label_set_long_mode(ui->screen_2_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_6, 18, 169);
    lv_obj_set_size(ui->screen_2_label_6, 100, 32);

    // Write style for screen_2_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_6, &lv_font_SourceHanSansCN_Normal_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_2_btn_2
    ui->screen_2_btn_2 = lv_btn_create(ui->screen_2);
    ui->screen_2_btn_2_label = lv_label_create(ui->screen_2_btn_2);
    lv_label_set_text(ui->screen_2_btn_2_label, "退出");
    lv_label_set_long_mode(ui->screen_2_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_2_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_2_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_2_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_2_btn_2, 244, 165);
    lv_obj_set_size(ui->screen_2_btn_2, 60, 60);

    // Write style for screen_2_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_2_btn_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_2_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_2_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_2_btn_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_btn_2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_btn_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_btn_2, &lv_font_SourceHanSansCN_Normal_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_btn_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_2_img_1
    ui->screen_2_img_1 = lv_img_create(ui->screen_2);
    lv_obj_add_flag(ui->screen_2_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_2_img_1, &_2_alpha_40x40);
    lv_img_set_pivot(ui->screen_2_img_1, 50, 50);
    lv_img_set_angle(ui->screen_2_img_1, 0);
    lv_obj_set_pos(ui->screen_2_img_1, 250, 13);
    lv_obj_set_size(ui->screen_2_img_1, 40, 40);

    // Write style for screen_2_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_2_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_2_img_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_2_img_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_2_img_2
    ui->screen_2_img_2 = lv_img_create(ui->screen_2);
    lv_obj_add_flag(ui->screen_2_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_2_img_2, &_GOP_TestCenter_LeftNav_Icon_alpha_40x40);
    lv_img_set_pivot(ui->screen_2_img_2, 50, 50);
    lv_img_set_angle(ui->screen_2_img_2, 0);
    lv_obj_set_pos(ui->screen_2_img_2, 250, 63);
    lv_obj_set_size(ui->screen_2_img_2, 40, 40);

    // Write style for screen_2_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_2_img_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_2_img_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_img_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_2_img_2, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of screen_2.

    // Update current screen layout.
    lv_obj_update_layout(ui->screen_2);

    // Init events for screen.
    events_init_screen_2(ui);
    lv_timer_create(screen_2_update_labels1, 10, ui);
    lv_timer_create(screen_2_update_labels2, 10, ui);
}
