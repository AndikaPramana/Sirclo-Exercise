<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class BodyweightModel extends CI_Model {

    // show all bodyweight data (descending order)
    public function getData(){
        $this->db->order_by('Date', 'desc');
        return $this->db->get('bodyrecord');
    }
  
    // show body record by date
    public function getData_by($date){
        $this->db->where('Date', $date);
        return $this->db->get('bodyrecord')->row();
    }
   
  // function to add record to database
  public function add(){

    // Gather all the data that we get from form on submit
    // put it inside $data as array
    $data = array(
      "Date" => $this->input->post('input_Date'),
      "Max" => $this->input->post('input_Max'),
      "Min" => $this->input->post('input_Min'),
      "Variance" => $this->input->post('input_Max')-$this->input->post('input_Min')
    );
    
    // then insert this data to database
    $this->db->insert('bodyrecord', $data); 
  }
  
  // Function to edit a record 
  public function edit($date){
    $data = array(
      "Max" => $this->input->post('input_Max'),
      "Min" => $this->input->post('input_Min'),
      "Variance" => $this->input->post('input_Max')-$this->input->post('input_Min')
    );
    
    $this->db->where('Date', $date);
    $this->db->update('bodyrecord', $data); 
  }
  
  // function to delete a record
  public function delete($date){
    $this->db->where('Date', $date);
    $this->db->delete('bodyrecord'); 
  }
}