/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    unisims_ver_m_12511392188679790854_2316096324_init();
    unisims_ver_m_12511392188679790854_0709700939_init();
    unisims_ver_m_17415101324312028692_3476364530_init();
    unisims_ver_m_17415101324312028692_0970595058_init();
    unisims_ver_m_13979362885179341725_3125220529_init();
    unisims_ver_m_13979362885179341725_2161410271_init();
    unisims_ver_m_00445221965264662842_2449448540_init();
    work_m_12542462607632439824_2625944998_init();
    work_m_11491833963429943931_2073120511_init();


    xsi_register_tops("work_m_12542462607632439824_2625944998");
    xsi_register_tops("work_m_11491833963429943931_2073120511");


    return xsi_run_simulation(argc, argv);

}
