<?php  if ( ! defined('BASEPATH')) exit('No direct script access allowed');
 
class BodyWeightController extends CI_Controller {

public function __construct(){
    parent::__construct();
    $this->load->model('BodyweightModel'); // Load BodyweightModel to controller
  }

  public function index(){
    // get the data from model and pass it to view
    $data['bodyrecord'] = $this->BodyweightModel->getData();
    $this->load->view('index', $data);
  }

  public function show($date){
    // get the data from model and pass it to view
    $data['bodyrecord'] = $this->BodyweightModel->getData_by($date);
    $this->load->view('showpage', $data);
  }
  
  public function create(){
    // if user click submit, then process the data, in this case, add
    if($this->input->post('submit')){ 
        $this->BodyweightModel->add();
        redirect('/');
    }

    $this->load->view('addrecord');
  }
  
  public function update($date){
    // if user click submit, then process the data, in this case, edit
    if($this->input->post('submit')){ 
        $this->BodyweightModel->edit($date); 
        redirect('/');
    }

    // get the data from model and pass it to view
    $data['bodyrecord'] = $this->BodyweightModel->getData_by($date);
    $this->load->view('editrecord', $data);
  }
  
  public function delete($date){
    // delete the data
    $this->BodyweightModel->delete($date); 
    redirect('/');
  }
}