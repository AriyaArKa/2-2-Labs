package com.example.test2;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class EmployeeAdapter extends RecyclerView.Adapter<EmployeeAdapter.EmployeeViewHolder>{

    private List<EmployeeInfo> employeeList;

    public EmployeeAdapter(List<EmployeeInfo> employeeList) {
        this.employeeList = employeeList;
    }

    @NonNull
    @Override
    public EmployeeViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.employee_item, parent, false);
        return new EmployeeViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull EmployeeViewHolder holder, int position) {
        EmployeeInfo employee = employeeList.get(position);
        holder.employeeName.setText(employee.getEmployeeName());
        holder.employeeContact.setText(employee.getEmployeeContactNumber());
        holder.employeeAddress.setText(employee.getEmployeeAddress());
    }

    @Override
    public int getItemCount() {
        return employeeList.size();
    }

    public static class EmployeeViewHolder extends RecyclerView.ViewHolder {
        TextView employeeName, employeeContact, employeeAddress;

        public EmployeeViewHolder(View itemView) {
            super(itemView);
            employeeName = itemView.findViewById(R.id.tvEmployeeName);
            employeeContact = itemView.findViewById(R.id.tvEmployeePhone);
            employeeAddress = itemView.findViewById(R.id.tvEmployeeAddress);
        }
    }
}
