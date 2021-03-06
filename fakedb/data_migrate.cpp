#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <vector>
#include <map>
#include <tuple>
#include <stdio.h>

#include "include/schema.h"
#include "include/storage.h"
#include "include/data_migrate.h"

using namespace std;

char CUSTOMER_TBL_FILE[40]="./../../tables/tpcc_customer.tbl";
char DISTRICT_TBL_FILE[40]="./../../tables/tpcc_district.tbl";
char HISTORY_TBL_FILE[40]="./../../tables/tpcc_history.tbl";
char ITEM_TBL_FILE[40]="./../../tables/tpcc_item.tbl";
char NEWORDER_TBL_FILE[40]="./../../tables/tpcc_neworder.tbl";
char ORDERLINE_TBL_FILE[40]="./../../tables/tpcc_orderline.tbl";
char ORDER_TBL_FILE[40]="./../../tables/tpcc_order.tbl";
char STOCK_TBL_FILE[40]="./../../tables/tpcc_stock.tbl";
char WAREHOUSE_TBL_FILE[40]="./../../tables/tpcc_warehouse.tbl";

int load_customer_from_file() {
	FILE *customer_tbl;

	customer_tbl=fopen(CUSTOMER_TBL_FILE, "r");
	customer temp_customer;

	while(!feof(customer_tbl)) {
		
		if(temp_customer.parse(&customer_tbl)==0)
		{
			temp_customer.insert();
		}
		else
		{
			//printf("EOF found\n");
		}
	}

	printf("No. of entries = %lld :: %s\n",temp_customer.count,__func__);

	fclose(customer_tbl);
	return 0;
}

int load_district_from_file() {
	FILE *district_tbl;

	district_tbl=fopen(DISTRICT_TBL_FILE, "r");
	district temp_district;

	while(!feof(district_tbl)) {
		
		if(temp_district.parse(&district_tbl)==0)
		{
			temp_district.insert();
		}
		else
		{
			//printf("EOF found\n");
		}
	}

	printf("No. of entries = %lld :: %s\n",temp_district.count,__func__);

	fclose(district_tbl);
	return 0;
}

int load_history_from_file() {
	FILE *history_tbl;

	history_tbl=fopen(HISTORY_TBL_FILE, "r");
	history temp_history;

	while(!feof(history_tbl)) {
		
		if(temp_history.parse(&history_tbl)==0)
		{
			temp_history.insert();
		}
		else
		{
			//printf("EOF found\n");
		}
	}

	printf("No. of entries = %lld :: %s\n",temp_history.count,__func__);

	fclose(history_tbl);
	return 0;
}

int load_item_from_file() {
	FILE *item_tbl;

	item_tbl=fopen(ITEM_TBL_FILE, "r");
	item temp_item;

	while(!feof(item_tbl)) {
		
		if(temp_item.parse(&item_tbl)==0)
		{
			temp_item.insert();
		}
		else
		{
			//printf("EOF found\n");
		}
	}

	printf("No. of entries = %lld :: %s\n",temp_item.count,__func__);

	fclose(item_tbl);
	return 0;
}

int load_neworder_from_file() {
	FILE *neworder_tbl;

	neworder_tbl=fopen(NEWORDER_TBL_FILE, "r");
	neworder temp_neworder;

	while(!feof(neworder_tbl)) {
		
		if(temp_neworder.parse(&neworder_tbl)==0)
		{
			temp_neworder.insert();
		}
		else
		{
			//printf("EOF found\n");
		}
	}

	printf("No. of entries = %lld :: %s\n",temp_neworder.count,__func__);

	fclose(neworder_tbl);
	return 0;
}

int load_order_from_file() {
	FILE *order_tbl;

	order_tbl=fopen(ORDER_TBL_FILE, "r");
	order temp_order;

	while(!feof(order_tbl)) {
		
		if(temp_order.parse(&order_tbl)==0)
		{
			temp_order.insert();
		}
		else
		{
			//printf("EOF found\n");
		}
	}

	printf("No. of entries = %lld :: %s\n",temp_order.count,__func__);

	fclose(order_tbl);
	return 0;
}

int load_orderline_from_file() {
	FILE *orderline_tbl;

	orderline_tbl=fopen(ORDERLINE_TBL_FILE, "r");
	orderline temp_orderline;

	while(!feof(orderline_tbl)) {
		
		if(temp_orderline.parse(&orderline_tbl)==0)
		{
			temp_orderline.insert();
		}
		else
		{
			//printf("EOF found\n");
		}
	}

	printf("No. of entries = %lld :: %s\n",temp_orderline.count,__func__);

	fclose(orderline_tbl);
	return 0;
}

int load_stock_from_file() {
	FILE *stock_tbl;

	stock_tbl=fopen(STOCK_TBL_FILE, "r");
	stock temp_stock;

	while(!feof(stock_tbl)) {
		
		if(temp_stock.parse(&stock_tbl)==0)
		{
			temp_stock.insert();
		}
		else
		{
			//printf("EOF found\n");
		}
	}

	printf("No. of entries = %lld :: %s\n",temp_stock.count,__func__);

	fclose(stock_tbl);
	return 0;
}

int load_warehouse_from_file() {
	FILE *warehouse_tbl;

	warehouse_tbl=fopen(WAREHOUSE_TBL_FILE, "r");
	warehouse temp_warehouse;

	while(!feof(warehouse_tbl)) {
		
		if(temp_warehouse.parse(&warehouse_tbl)==0)
		{
			temp_warehouse.insert();
		}
		else
		{
			//printf("EOF found\n");
		}
	}

	printf("No. of entries = %lld :: %s\n",temp_warehouse.count,__func__);

	fclose(warehouse_tbl);
	return 0;
}