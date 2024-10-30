transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+/home/hw_lab/b230593cs/program2 {/home/hw_lab/b230593cs/program2/fsb.v}
vlog -vlog01compat -work work +incdir+/home/hw_lab/b230593cs/program2 {/home/hw_lab/b230593cs/program2/fsb8.v}

vlog -vlog01compat -work work +incdir+/home/hw_lab/b230593cs/program2 {/home/hw_lab/b230593cs/program2/fsb8_tb.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L fiftyfivenm_ver -L rtl_work -L work -voptargs="+acc"  fsb8_tb

add wave *
view structure
view signals
run -all
